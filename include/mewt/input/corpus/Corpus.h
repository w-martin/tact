/**
 * @file Corpus.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef CORPUS_H
#define	CORPUS_H

#include <string>
#include <vector>
#include <memory>

#include "mewt/input/corpus/Document.h"

using std::string;
using std::vector;
using std::auto_ptr;

/**
 * Store of Document objects.
 * 
 */
class Corpus {
public:
    /**
     * Default constructor.
     * 
     * @param location the location of the corpus on disk.
     * 
     */
    Corpus(string const location);
    /**
     * Copy constructor.
     * 
     * @param orig the Corpus to copy.
     * 
     */
    Corpus(const Corpus& orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~Corpus();
    /**
     * Gets the location of this Corpus.
     * 
     * @return the location of this Corpus.
     * 
     */
    string const getLocation() const;
    /**
     * Gets the size of this Corpus.
     * 
     * @return the size of this Corpus.
     * 
     */
    int const getSize() const;
protected:
    /**
     * Gets the Documents that constitute this Corpus.
     * 
     * @return the Documents that constitute this Corpus.
     *
     */
    vector< Document * > const * const getDocuments() const;
    /**
     * Adds a Document to this Corpus if it is not already present.
     * 
     * @param document the Document to add.
     * @return true if the Document was added, false otherwise.
     * 
     */
    bool const addDocument(auto_ptr<Document> document);
private:
    string location;
    vector< Document * > * documents;
};

#endif	/* CORPUS_H */
