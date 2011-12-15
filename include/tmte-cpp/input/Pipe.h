/**
 * @file Pipe.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef PIPE_H
#define	PIPE_H

#include "tmte-cpp/input/exceptions/AlphabetSetException.h"
#include "tmte-cpp/input/Instance.h"
#include "tmte-cpp/model/Alphabet.h"
#include <vector>
#include <memory>

using std::vector;
using std::auto_ptr;

/**
 * Pipe class for transforming Instance objects.
 * 
 */
class Pipe : vector<Instance> {
public:
    Pipe();
    Pipe(const Pipe& orig);
    virtual ~Pipe();
    /**
     * Gets the data Alphabet.
     * 
     * @return the data Alphabet.
     * 
     */
    Alphabet const * const getDataAlphabet() const;
    /**
     * Sets the data Alphabet.
     * 
     * @param dataAlphabet the data Alphabet.
     * 
     */
    void setDataAlphabet(auto_ptr<Alphabet> dataAlphabet)
    throw (AlphabetSetException);
    /**
     * Gets the target Alphabet.
     * 
     * @return the target Alphabet.
     * 
     */
    Alphabet const * const getTargetAlphabet() const;
    /**
     * Sets the target Alphabet.
     * 
     * @param targetAlphabet the target Alphabet.
     * 
     */
    void setTargetAlphabet(auto_ptr<Alphabet> targetAlphabet)
    throw (AlphabetSetException);
    /**
     * Performs the pipe operation of this Pipe.
     * 
     * @param instance the Instance to perform the pipe operation on.
     * @return the transformed Instance.
     * 
     */
    virtual Instance const pipe(Instance const & instance) const;
private:
    auto_ptr<Alphabet> dataAlphabet;
    auto_ptr<Alphabet> targetAlphabet;
};

#endif	/* PIPE_H */
