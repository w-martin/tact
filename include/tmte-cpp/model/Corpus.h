/**
 * @file Corpus.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef CORPUS_H
#define	CORPUS_H

#include "tmte-cpp/model/Document.h"
#include <utility>
#include <vector>

using std::auto_ptr;
using std::vector;

/**
 * Represents a collection of related documents.
 * 
 */
class Corpus {
public:
    /**
     * Default constructor.
     * 
     */
    Corpus();
    virtual ~Corpus();
    /**
     * Gets the list of Document pointers.
     * 
     * @return the list of Document pointers.
     * 
     */
    vector<Document const *> const * const getDocuments() const;
    /**
     * Adds the given Document to the list of Documents.
     * 
     * @param document the Document to add.
     * 
     */
    void addDocument(auto_ptr<Document> document);
    /**
     * Gets the number of terms in this Corpus.
     * 
     * @return the number of terms in this Corpus.
     * 
     */
    int const getNoTerms() const;
    /**
     * Sets the number of terms in this Corpus.
     * 
     * @param noTerms the number of terms in this Corpus.
     * 
     */
    void setNoTerms(int const noTerms);
private:
    vector<Document const *> * documents;
    int noTerms;
};

#endif	/* CORPUS_H */

