/**
 * @file Document.h
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

#ifndef DOCUMENT_H
#define	DOCUMENT_H

#include <utility>
#include <vector>

using std::auto_ptr;
using std::vector;

/**
 * Represents a Document class.
 * 
 * @param length the length of this Document's file.
 * 
 */
class Document {
public:
    /**
     * Default constructor.
     * 
     */
    Document(int const length);
    virtual ~Document();
    /**
     * Gets the words.
     * 
     * @return the words.
     * 
     */
    vector<char const *> const * const getWords() const;
    /**
     * Adds the given word with its corresponding count.
     * 
     * @param word the word to add.
     * @param count the count of the given word.
     * 
     */
    void addWord(auto_ptr<char const> word, int const count);
    /**
     * Gets the counts.
     * 
     * @return the counts.
     * 
     */
    vector<int> const * const getCounts() const;
    /**
     * Gets the length.
     * 
     * @return the length.
     * 
     */
    int const getLength() const;
    /**
     * Gets the total.
     * 
     * @return the total.
     * 
     */
    int const getTotal() const;
private:
    vector<char const *> * words;
    vector<int> * counts;
    int length;
    int total;
};

#endif	/* DOCUMENT_H */

