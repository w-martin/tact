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

