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

#include "mewt/input/corpus/feature/AlphabetIterator.h"
#include "mewt/input/corpus/feature/exceptions/TermNotPresentException.h"
#include <string>
#include <vector>
#include <boost/bimap.hpp>

using std::auto_ptr;
using std::string;
using std::vector;
using boost::bimaps::bimap;

typedef bimap< string, int > bmType;

/**
 * Represents a finite collection of terms.
 * 
 */
class Alphabet {
public:
    /**
     * Default constructor.
     * 
     */
    Alphabet();
    /**
     * Copy constructor.
     * 
     * @param orig the object to copy from.
     * 
     */
    Alphabet(Alphabet const & orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~Alphabet();
    /**
     * Adds the given term to this Alphabet.
     * 
     * @param term the term to add.
     * @return the index of the added term.
     * 
     */
    int const addTerm(string const term);
    /**
     * Gets the AlphabetIterator pointing to the first element.
     * 
     * @return the AlphabetIterator pointing to the first element.
     * 
     */
    AlphabetIterator const begin() const;
    /**
     * Gets the AlphabetIterator pointing to the last element.
     * 
     * @return the AlphabetIterator pointing to the last element.
     * 
     */
    AlphabetIterator const end() const;
    /**
     * Checks if this Alphabet is equal to the other Alphabet.
     * 
     * @param other the Alphabet to check against.
     * @return true if this Alphabet is equal to the other Alphabet, false
     * otherwise.
     * 
     */
    bool const equals(Alphabet const * const other) const;
    /**
     * Gets the index of the given term.
     * 
     * @param term the term to get the index of.
     * @return the index of the given term.
     * @throws TermNotPresentException if the term is not present.
     * 
     */
    int const getIndex(string const & term) const
    throw (TermNotPresentException);
    /**
     * Gets the next index.
     * 
     * @return the next index.
     * 
     */
    int const getNextIndex() const;
    /**
     * Gets the size of this Alphabet.
     * 
     * @return the size of this Alphabet.
     * 
     */
    const int getSize() const;
    /**
     * Gets the term with the given index.
     * 
     * @param index the index of the term to get.
     * @return the term with the given index.
     * @throws TermNotPresentException if the term is not present.
     * 
     */
    string const getTerm(int const & index) const
    throw (TermNotPresentException);
    /**
     * Checks if the given term is present in this Alphabet.
     * 
     * @param term the term to check for.
     * @return true if the term is present, false otherwise.
     * 
     */
    bool const hasTerm(string const & term) const;
    /**
     * Removes the term with the given index.
     * 
     * @param index the index of the term to remove.
     * @return the term that was removed.
     * @throws TermNotPresentException if the term is not present 
     * in this Alphabet.
     * 
     */
    string const removeTerm(int const & index)
    throw (TermNotPresentException);
    /**
     * Removes the given term from this Alphabet.
     * 
     * @param term the term to remove.
     * @return the index of the term that was removed.
     * @throws TermNotPresentException if the term is not present 
     * in this Alphabet.
     * 
     */
    int const removeTerm(string const & term)
    throw (TermNotPresentException);
protected:
    /**
     * Creates an exception with information about the given index.
     * 
     * @param index the index that caused this exception.
     * @return an exception with information about the given index.
     * 
     */
    TermNotPresentException const createExceptionWithIndex(
            int const index) const;
    /**
     * Gets the data from this Alphabet.
     * 
     * @return the data from this Alphabet.
     * 
     */
    bmType const * const getData() const;
private:
    /**
     * The data in this Alphabet.
     * 
     */
    bmType * data;
    /**
     * The next index which will be assigned to a term.
     * 
     */
    int nextIndex;
};

#endif	/* ALPHABET_H */
