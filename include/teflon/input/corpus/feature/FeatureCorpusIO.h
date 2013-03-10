/**
 * @file FeatureCorpusIO.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 *
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef FEATURECORPUSIO_H
#define FEATURECORPUSIO_H

#define IO_CACHE "tefloncache/"
#define IO_CORPUS_INFO "corpus.info"
#define IO_CORPUS_ALPHABET "alphabet"
#define IO_CORPUS_DOCUMENTS "documents/"

#include "teflon/input/exceptions/CorpusNotFoundException.h"
#include "teflon/input/corpus/feature/FeatureCorpus.h"
#include "teflon/util/exceptions/FileNotFoundException.h"

/**
 * Name-space for loading and saving a FeatureCorpus.
 *
 */
namespace FeatureCorpusIO {
/**
 * Clears all saved corpora.
 *
 */
void clearCache();
/**
 * Deletes a saved FeatureCorpus.
 *
 * @param location the original  location of the saved Corpus.
 * @throw CorpusNotFoundException if the Corpus with the given location
 * was not previously saved.
 *
 */
void deleteCorpus(string const & location) throw (CorpusNotFoundException);
/**
 * Loads a saved FeatureCorpus.
 *
 * @param location the original  location of the saved Corpus.
 * @return the loaded Corpus.
 * @throw CorpusNotFoundException if the Corpus with the given location
 * was not previously saved.
 *
 */
auto_ptr< FeatureCorpus > load(string const & location)
throw (CorpusNotFoundException);
/**
 * Saves a FeatureCorpus.
 *
 * @param Corpus the Corpus to save.
 *
 */
void save(FeatureCorpus const * const corpus);

/**
 * Name-space for utility methods for the FeatureCorpusIO name-space.
 *
 */
namespace util {
/**
 * Creates the directory with the given number in the given base
 * directory.
 *
 * @param directory the base directory.
 * @param directoryNumber the number of the directory.
 * @return the name of the created directory.
 *
 */
string const createDirectory(string const & directory,
                             int const & directoryNumber);
/**
 * Finds the next free directory for saving a Corpus.
 *
 * @return the next
 * free directory for saving a Corpus.
 *
 */
string const findNextFreeDirectory();
/**
 * Finds the saved Corpus with the given original location.
 *
 * @param location the original location of the Corpus.
 * @return the location of the saved Corpus.
 * @throw CorpusNotFoundException if the Corpus with the given location
 * was not previously saved.
 *
 */
string const findSavedCorpus(string const & location)
throw (CorpusNotFoundException);
/**
 * Loads the Alphabet from the given directory.
 *
 * @param directory the directory to load the Alphabet from.
 * @return the Alphabet loaded from the given directory.
 * @throw FileNotFoundException if the Alphabet file was not found.
 *
 */
auto_ptr< Alphabet > loadAlphabet(string const & directory)
throw (FileNotFoundException, DuplicateException);
/**
 * Loads the FeatureDocument from the file with the given name.
 *
 * @param fileName the name of the file to load from.
 * @param alphabet the Alphabet of the FeatureDocument to load.
 * @return the loaded FeatureDocument from the file with the given
 * name.
 * @throw FileNotFoundException if the Document file was not found.
 * @throw TermNotPresentException if a feature was found in the
 * loaded FeatureDocument that is not present in the given Alphabet.
 *
 */
auto_ptr< FeatureDocument > loadDocument(string const & fileName,
    Alphabet const * const alphabet)
throw (FileNotFoundException, TermNotPresentException);
/**
 * Loads the FeatureDocuments from the given directory with the given
 * Alphabet, and adds them to the given FeatureCorpus.
 *
 * @param directory the directory to load FeatureDocuments from.
 * @param alphabet the Alphabet the the FeatureDocuments use.
 * @param corpus the Corpus to load the FeatureDocuments in to.
 * @throw TermNotPresentException if a saved FeatureDocument used a
 * term that is not present in the given Alphabet.
 *
 */
void loadDocuments(string const & directory,
                   Alphabet const * const alphabet, FeatureCorpus * const corpus)
throw (TermNotPresentException);
/**
 * Loads the FeatureDocuments from the given directory with the given
 * Alphabet, and adds them to the given FeatureCorpus.
 *
 * @param directory the directory to load FeatureDocuments from.
 * @param alphabet the Alphabet the the FeatureDocuments use.
 * @param corpus the Corpus to load the FeatureDocuments in to.
 * @throw TermNotPresentException if a saved FeatureDocument used a
 * term that is not present in the given Alphabet.
 *
 */
void loadDocumentsFromDirectory(string const & directory,
                                Alphabet const * const alphabet, FeatureCorpus * const corpus)
throw (TermNotPresentException);
/**
 * Loads the Corpus name from the given directory.
 *
 * @param directory the directory to load the Corpus name from.
 * @return the Corpus name loaded from the given directory.
 * @throw FileNotFoundException if the corpus info file was not found.
 *
 */
string const loadName(string const & directory)
throw (FileNotFoundException);
/**
 * Saves the given Alphabet in the given directory.
 *
 * @param directory the directory to save the Alphabet in.
 * @param alphabet the Alphabet to save.
 *
 */
void saveAlphabet(string const & directory,
                  Alphabet const * const alphabet);
/**
 * Saves the given FeatureDocument to the given directory.
 *
 * @param directory the directory to save the FeatureDocument in.
 * @param n the number of the FeatureDocument to save.
 * @param document the FeatureDocument to save.
 *
 */
void saveDocument(string const & directory, int const & n,
                  FeatureDocument const * const document);
/**
 * Saves the given Documents to the given directory.
 *
 * @param directory the Directory to save the Documents in.
 * @param documents the Documents to save.
 * @throw IncompatibleCorpusException if the Documents were of an
 * incompatible type.
 *
 */
void saveDocuments(string const & directory,
                   vector< Document * > const * const documents)
throw (IncompatibleCorpusException);
/**
 * Saves the info file for the given Corpus in the given directory.
 *
 * @param directory the directory to save the file in.
 * @param Corpus the Corpus to save an info file for.
 *
 */
void saveInfoFile(string const & directory,
                  FeatureCorpus const * const corpus);
}
};

#endif /* FEATURECORPUSIO_H */
