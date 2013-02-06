/**
 * @file StopwordFilter.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "mewt/input/pipe/StopwordFilter.h"
#include "mewt/input/pipe/DirectoryScannerPipe.h"
#include "mewt/input/corpus/feature/FeatureDocument.h"
#include "mewt/input/corpus/feature/FeatureCorpus.h"
#include "mewt/input/pipe/bundle/InputOptimiseBundle.h"

using namespace mewt::input::pipe;

StopwordFilter::StopwordFilter(string const & stopwordsFile)
: Pipe(DOCUMENT_TYPE_FEATURE) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
          new Corpus(".", DOCUMENT_TYPE_BASIC));
  corpus->addDocument(auto_ptr< Document > (new Document(stopwordsFile)));
  corpus = InputOptimiseBundle().pipe(corpus);
  stopwords = new Alphabet(*((FeatureCorpus *) corpus.get())->getAlphabet());
}

StopwordFilter::StopwordFilter(string const & stopwordsDirectory,
        bool const & recursive)
: Pipe(DOCUMENT_TYPE_FEATURE) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
          new Corpus(stopwordsDirectory, DOCUMENT_TYPE_BASIC));
  DirectoryScannerPipe pipe(recursive);
  pipe.attachPipe(auto_ptr< Pipe > (new InputOptimiseBundle()));
  corpus = pipe.pipe(corpus);
  stopwords = new Alphabet(*((FeatureCorpus *) corpus.get())->getAlphabet());
}

StopwordFilter::StopwordFilter(Alphabet const * const stopwords) {
  StopwordFilter::stopwords = new Alphabet(*stopwords);
}

StopwordFilter::StopwordFilter(StopwordFilter const & orig)
: Pipe(DOCUMENT_TYPE_FEATURE) {
  stopwords = new Alphabet(*orig.getStopwords());
}

StopwordFilter::~StopwordFilter() {
  delete stopwords;
}

Alphabet const * const StopwordFilter::getStopwords() const {
  return stopwords;
}

auto_ptr< Corpus > StopwordFilter::process(auto_ptr<Corpus> corpus) const {
  vector< string > const empty;
  vector< string > termsToReplace;
  for (AlphabetIterator iter = stopwords->begin();
          stopwords->end() != iter; iter++) {
    string const term = iter.getTerm();
    termsToReplace.push_back(term);
  }
  for (vector< string >::const_iterator iter = termsToReplace.begin();
          termsToReplace.end() != iter; iter++) {
    ((FeatureCorpus *) corpus.get())->replaceTerm(*iter, empty);
  }
  return corpus;
}
