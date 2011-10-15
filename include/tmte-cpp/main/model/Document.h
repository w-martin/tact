/**
 * @file Document.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 *
 * @section DESCRIPTION
 *
 * 
 */

#ifndef DOCUMENT_H
#define	DOCUMENT_H

#include "tmte-cpp/main/util/exceptions/IllegalArgumentException.h"

/**
 * Represents a Document class.
 * 
 * @param words the words.
 * @param counts the counts.
 * @param length the length.
 * @param total the total.
 * 
 */
class Document {
public:
    Document(
            int const * const words,
            int const * const counts,
            int const length,
            int const total)
    throw (IllegalArgumentException);
    virtual ~Document();
    /**
     * Gets the words.
     * 
     * @return the words.
     * 
     */
    int const * const getWords() const;
    /**
     * Gets the counts.
     * 
     * @return the counts.
     * 
     */
    int const * const getCounts() const;
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
    int const * words;
    int const * counts;
    int length;
    int total;
};

#endif	/* DOCUMENT_H */

