/**
 * @file Pipe.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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

#include "mewt/input/Pipe.h"

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
