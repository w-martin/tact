/**
 * @file Document.cpp
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
 * Represents a Document class.
 * 
 */

#include "tmte-cpp/main/model/Document.h"

Document::Document(
        int const * const words,
        int const * const counts,
        int const length,
        int const total)
throw (IllegalArgumentException) {
    Document::words = words;
    Document::counts = counts;
    Document::length = length;
    Document::total = total;
}

int const * const Document::getWords() const {
    return Document::words;
}

int const * const Document::getCounts() const {
    return Document::counts;
}

int const Document::getLength() const {
    return Document::length;
}

int const Document::getTotal() const {
    return total;
}
