/**
 * @file StopwordFilter.h
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

#ifndef STOPWORDFILTER_H
#define STOPWORDFILTER_H

#include "teflon/input/corpus/feature/Alphabet.h"
#include "teflon/input/pipe/Pipe.h"

class StopwordFilter : public Pipe {
public:
    /**
     * File constructor.
     * 
     * @param stopwordsFile the location of the file containing stop-words.
     * 
     */
    StopwordFilter(string const & stopwordsFile);
    /**
     * Directory constructor.
     * 
     * @param stopwordsDirectory the directory containing stop-word files.
     * @param recursive whether the directory should be scanned recursively.
     * 
     */
    StopwordFilter(string const & stopwordsDirectory, bool const & recursive);
    /**
     * Specific constructor.
     * 
     * @param stopwords a list of stop-words.
     * 
     */
    StopwordFilter(Alphabet const * const stopwords);
    /**
     * Copy constructor.
     * 
     * @param orig the StopwordFilter to copy.
     * 
     */
    StopwordFilter(StopwordFilter const & orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~StopwordFilter();
    /**
     * Gets the Alphabet of stop-words.
     * 
     * @return the Alphabet of stop-words.
     * 
     */
    Alphabet const * const getStopwords() const;
protected:
    /**
     * Alphabet of stop-words.
     * 
     */
    Alphabet const * stopwords;
private:
    /**
     * Process the given corpus.
     * 
     * @param corpus the Corpus to process.
     * @return the processed Corpus.
     * 
     */
    auto_ptr< Corpus > process(auto_ptr< Corpus > corpus) const;

};

#endif /* STOPWORDFILTER_H */
