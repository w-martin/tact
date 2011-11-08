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
#include <memory>
#include "tmte-cpp/main/model/exceptions/DuplicatedWordException.h"

using std::auto_ptr;
using std::vector;

/**
 * Represents a finite collection of words.
 * 
 */
class Alphabet {
public:
    Alphabet();
    Alphabet(const Alphabet& orig);
    virtual ~Alphabet();
    /**
     * Gets the size of this Alphabet.
     * 
     * @return the size of this Alphabet.
     * 
     */
    virtual const int getSize() const;
    virtual vector<char*> const getWords() const;
    virtual int const addWord(auto_ptr<char*> word)
    throw (DuplicatedWordException);
private:
    vector<auto_ptr<char* > > const * words;
    vector<int> const * indices;
    int nextIndex;
};

#endif	/* ALPHABET_H */

