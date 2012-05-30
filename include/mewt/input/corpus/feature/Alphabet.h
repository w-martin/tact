/**
 * @file Alphabet.h
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

#ifndef ALPHABET_H
#define	ALPHABET_H

#include "mewt/model/exceptions/DuplicatedWordException.h"
#include "mewt/model/exceptions/WordNotPresentException.h"
#include <string>
#include <vector>

using std::auto_ptr;
using std::vector;
using std::string;

/**
 * Represents a finite collection of words.
 * 
 */
class Alphabet {
public:
    Alphabet();
    Alphabet(Alphabet const & orig);
    virtual ~Alphabet();
    /**
     * Gets the size of this Alphabet.
     * 
     * @return the size of this Alphabet.
     * 
     */
    const int getSize() const;
    /**
     * Gets the array of words.
     * 
     * @return the array of words.
     * 
     */
    vector<string> const * const getWords() const;
    /**
     * Adds the given word to this Alphabet.
     * 
     * @param word the word to add.
     * @return the index of the added word.
     * @throws DuplicatedWordException if the word is already present.
     * 
     */
    int const addWord(string const word)
    throw (DuplicatedWordException);
    /**
     * Removes the word with the given index.
     * 
     * @param index the index of the word to remove.
     * @return the word that was removed.
     * @throws WordNotPresentException if the word is not present 
     * in this Alphabet.
     * 
     */
    string const removeWord(int const index)
    throw (WordNotPresentException);
    /**
     * Removes the given word from this Alphabet.
     * 
     * @param word the word to remove.
     * @return the index of the word that was removed.
     * @throws WordNotPresentException if the word is not present 
     * in this Alphabet.
     * 
     */
    int const removeWord(string const word)
    throw (WordNotPresentException);
    /**
     * Checks if the given word is present in this Alphabet.
     * 
     * @param word the word to check for.
     * @return true if the word is present, false otherwise.
     * 
     */
    bool const hasWord(string const word) const;
    /**
     * Gets the array of indices.
     * 
     * @return the array of indices.
     * 
     */
    vector<int> const * const getIndices() const;
    /**
     * Gets the index of the given word.
     * 
     * @param word the word to get the index of.
     * @return the index of the given word.
     * @throws WordNotPresentException if the word is not present.
     * 
     */
    int const getIndex(string const word) const
    throw (WordNotPresentException);
    /**
     * Gets the word with the given index.
     * 
     * @param index the index of the word to get.
     * @return the word with the given index.
     * @throws WordNotPresentException if the word is not present.
     * 
     */
    string const getWord(int const index) const
    throw (WordNotPresentException);
    /**
     * Gets the next index.
     * 
     * @return the next index.
     * 
     */
    int const getNextIndex() const;
protected:
    /**
     * Deletes the given word from this Alphabet.
     * 
     * @param word the word to delete.
     * 
     */
    void deleteWord(string const word);
    /**
     * Deletes the given index from this Alphabet.
     * 
     * @param index the index to delete.
     * 
     */
    void deleteIndex(int const index);
private:
    vector<string> * words;
    vector<int> * indices;
    int nextIndex;
};

#endif	/* ALPHABET_H */

