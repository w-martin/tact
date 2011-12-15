/**
 * @file Pipe.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/input/Pipe.h"

Pipe::Pipe() {
}

Pipe::Pipe(const Pipe& orig) {
    if (0 != orig.getDataAlphabet()) {
        dataAlphabet = auto_ptr<Alphabet > (
                new Alphabet(*orig.getDataAlphabet()));
    }
    if (0 != orig.getTargetAlphabet()) {
        targetAlphabet = auto_ptr<Alphabet > (
                new Alphabet(*orig.getTargetAlphabet()));
    }
}

Pipe::~Pipe() {
}

Alphabet const * const Pipe::getDataAlphabet() const {
    return dataAlphabet.get();
}

void Pipe::setDataAlphabet(auto_ptr<Alphabet> dataAlphabet)
throw (AlphabetSetException) {
    if (0 != Pipe::dataAlphabet.get()
            && Pipe::dataAlphabet->getSize() > 0) {
        throw AlphabetSetException();
    } else {
        Pipe::dataAlphabet = dataAlphabet;
    }
}

Alphabet const * const Pipe::getTargetAlphabet() const {
    return targetAlphabet.get();
}

void Pipe::setTargetAlphabet(auto_ptr<Alphabet> targetAlphabet)
throw (AlphabetSetException) {
    if (0 != Pipe::targetAlphabet.get()
            && Pipe::targetAlphabet->getSize() > 0) {
        throw AlphabetSetException();
    } else {
        Pipe::targetAlphabet = targetAlphabet;
    }
}

Instance const Pipe::pipe(Instance const & instance) const {
    return instance;
}
