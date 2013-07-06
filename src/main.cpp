/**
 * @file main.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.0
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * This is the main entry point at runtime.
 *
 */

#include "tact/input/pipe/bundle/CompleteFilteredBundle.h"
#include "tact/input/corpus/feature/FeatureCorpusIO.h"
#include "tact/util/Strings.h"
#include "tact/input/pipe/bundle/ScanInputOptimiseBundle.h"
#include "tact/algorithm/LDA.h"
#include <iostream>
#include <map>

namespace strings = tact::util::strings;

using std::cout;
using std::endl;
using std::map;

namespace {

namespace Input {

/**
 * Processes the corpus with given location.
 *
 * @param corpusLocation the location of the corpus.
 *
 */
auto_ptr< Corpus > process(string const & corpusLocation);

/**
 * Processes the corpus with given location.
 *
 * @param corpusLocation the location of the corpus.
 * @param stopwordsFile the location of the stop-words file, or NULL if
 * none is to be used.
 *
 */
auto_ptr< Corpus > process(string const & corpusLocation,
                           string const & stopwordsFile);
}

namespace Operation {

/**
 * Enumeration of possible operation modes.
 *
 */
enum Mode {
  CLEAR,
  INVALID,
  MODELLING,
  PREPROCESSING
};

/**
 * Clears the cache of any saved corpora.
 *
 */
void clear() {
  FeatureCorpusIO::clearCache();
}

/**
 * Parses the given string to get the operation mode.
 *
 * @param mode the string to parse.
 * @return the operation mode.
 *
 */
Mode getMode(string const & mode) {
  if (strings::matches(mode, "-c")) {
    return CLEAR;
  } else if (strings::matches(mode, "-m")) {
    return MODELLING;
  } else if (strings::matches(mode, "-p")) {
    return PREPROCESSING;
  } else {
    return INVALID;
  }
}

/**
 * Pre-processes the corpus with given location.
 *
 * @param corpusLocation the location of the corpus.
 *
 */
void preprocess(string const & corpusLocation) {
  auto_ptr< Corpus > corpus = Input::process(corpusLocation);
  FeatureCorpusIO::save((FeatureCorpus *) corpus.get());
}

/**
 * Pre-processes the corpus with given location.
 *
 * @param corpusLocation the location of the corpus.
 * @param stopwordsFile the location of the stop-words file, or NULL if
 * none is to be used.
 *
 */
void preprocess(string const & corpusLocation,
                string const & stopwordsFile) {
  auto_ptr< Corpus > corpus = Input::process(corpusLocation, stopwordsFile);
  FeatureCorpusIO::save((FeatureCorpus *) corpus.get());
}

}

namespace Input {

/**
 * Enumeration of possible input modes.
 *
 */
enum Mode {
  INVALID,
  LOAD,
  PROCESS
};

/**
 * Parses the given string to get the input mode.
 *
 * @param mode the string to parse.
 * @return the input mode.
 *
 */
Mode getMode(string const & mode) {
  if (strings::matches(mode, "-l")) {
    return LOAD;
  } else if (strings::matches(mode, "-p")) {
    return PROCESS;
  } else {
    return INVALID;
  }
}

/**
 * Loads the corpus from the cache.
 *
 * @param corpusLocation the original location of the corpus.
 * @return the loaded corpus.
 * @throw CorpusNotFoundException if the cached corpus was not found.
 *
 */
auto_ptr< Corpus > load(string const & corpusLocation)
throw (CorpusNotFoundException) {
  return auto_ptr< Corpus > (
           FeatureCorpusIO::load(corpusLocation).release());
}

/**
 * Processes the corpus with given location.
 *
 * @param corpusLocation the location of the corpus.
 *
 */
auto_ptr< Corpus > process(string const & corpusLocation) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(corpusLocation, DOCUMENT_TYPE_BASIC));
  corpus = ScanInputOptimiseBundle().pipe(corpus);
  return corpus;
}

/**
 * Processes the corpus with given location.
 *
 * @param corpusLocation the location of the corpus.
 * @param stopwordsFile the location of the stop-words file, or NULL if
 * none is to be used.
 *
 */
auto_ptr< Corpus > process(string const & corpusLocation,
                           string const & stopwordsFile) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(corpusLocation, DOCUMENT_TYPE_BASIC));
  corpus = CompleteFilteredBundle(stopwordsFile). pipe(corpus);
  return corpus;
}
}

/**
 * Prints the usage instructions.
 *
 */
void printUsage() {
  cout << "Usage: tact <mode> <arguments>"
       << endl;
  cout << "  Modes:" << endl;
  cout << "    -c" << endl;
  cout << "        Clears any saved corpora." << endl;
  cout << "    -p <corpus directory> <optional stopwords file>" << endl;
  cout << "        Pre process corpus and save it for later." << endl;
  cout << "    -m <output directory> <input mode> <input arguments>"
       << endl;
  cout << "        Model the corpus and save results to the given " <<
       "directory." << endl;
  cout << "  Input modes:" << endl;
  cout << "    -l <corpus directory>" << endl;
  cout << "        Loads a pre-processed corpus that had the given " <<
       "location at the time it was processed." << endl;
  cout << "    -p <corpus directory> <optional stopwords file>" << endl;
  cout << "        Processes the given corpus and uses it as input."
       << endl;
  cout << "Examples:" << endl;
  cout << "  tact -p myCorpus/" << "; tact -m output/ -l myCorpus/"
       << endl;
  cout << "  tact -m output -i myCorpus" << endl;
}
}

/**
 * Main entry point for the program.
 *
 * @param argc number of arguments.
 * @param argv string arguments from <code>stdin</code>.
 *
 */
int main(int argc, char** argv) {
  if (2 > argc) {
    printUsage();
    return 1;
  } else {
    Operation::Mode operationMode = Operation::getMode(argv[1]);
    cout << "Operation mode: ";
    switch (operationMode) {
    case Operation::CLEAR: {
      cout << "Clear saved corpora." << endl;
      Operation::clear();
      break;
    }
    case Operation::INVALID: {
      cout << "Invalid. Exiting." << endl;
      printUsage();
      return 1;
    }
    case Operation::MODELLING: {
      cout << "Modelling." << endl;
      if (5 > argc) {
        cout << "Error. Insufficient arguments." << endl;
        printUsage();
        return 1;
      } else {
        string const outputDirectory = argv[2];
        Input::Mode inputMode = Input::getMode(argv[3]);
        auto_ptr< Corpus > corpus;
        cout << "Input mode: ";
        switch (inputMode) {
        case Input::INVALID: {
          cout << "Invalid. Exiting." << endl;
          printUsage();
          return 1;
        }
        case Input::LOAD: {
          cout << "Load corpus ";
          string const corpusName = argv[4];
          cout << corpusName << "." << endl;
          try {
            corpus = Input::load(corpusName);
          } catch (CorpusNotFoundException const & cnfe) {
            cout << cnfe.what() << endl;
            return 1;
          }
          break;
        }
        case Input::PROCESS: {
          cout << "Process." << endl;
          if (6 <= argc) {
            corpus = Input::process(argv[4], argv[5]);
          } else {
            corpus = Input::process(argv[4]);
          }
          break;
        }
        }
        cout << "Input completed." << endl;
        int const noTopics = 100;
        double const alpha = 50 / noTopics;
        double const beta = 0.1;
        LDA * lda = new LDA(alpha, beta, corpus, noTopics);
        int const noIterations = 100;
        int const saveInterval = 1;
        lda->estimate(noIterations, outputDirectory, saveInterval);
      }
      break;
    }
    case Operation::PREPROCESSING: {
      cout << "Preprocessing." << endl;
      if (3 > argc) {
        cout << "Error. Insufficient arguments." << endl;
        printUsage();
        return 1;
      }
      if (4 <= argc) {
        Operation::preprocess(argv[2], argv[3]);
      } else {
        Operation::preprocess(argv[2]);
      }
      break;
    }
    }
    return 0;
  }
}
