/**
 * @file Corpus.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef CORPUS_H
#define	CORPUS_H

#include <utility>

using std::auto_ptr;

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
    Document const * const * const getDocuments() const;
    /**
     * Adds the given Document to the list of Documents.
     * 
     * @param document the Document to add.
     * 
     */
    void addDocument(auto_ptr<Document> const document);
    /**
     * Gets the number of Documents in this Corpus.
     * 
     * @return the number of Documents in this Corpus.
     * 
     */
    int const getNoDocuments() const;
    /**
     * Sets the number of Documents in this Corpus.
     * 
     * @param noDocuments the number of Documents in this Corpus.
     * 
     */
    void setNoDocuments(int const noDocuments);
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
    auto_ptr<Document> const * const documents;
    int noDocuments;
    int noTerms;
};

#endif	/* CORPUS_H */

