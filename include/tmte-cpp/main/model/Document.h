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
     * Gets the number of words.
     * 
     * @return the number of words.
     * 
     */
    int const getNoWords() const;
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
    int noWords;
    int length;
    int total;
};

#endif	/* DOCUMENT_H */

