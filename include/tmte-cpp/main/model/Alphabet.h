/**
 * @file Alphabet.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef ALPHABET_H
#define	ALPHABET_H

#include <vector>
#include <string>
#include "tmte-cpp/main/model/exceptions/DuplicatedWordException.h"
#include "tmte-cpp/main/model/exceptions/WordNotPresentException.h"

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
     * 
     */
    int const getIndex(string const word) const
    throw (WordNotPresentException);
private:
    vector<string> * words;
    vector<int> * indices;
    int noWords;
    int nextIndex;
};

#endif	/* ALPHABET_H */

