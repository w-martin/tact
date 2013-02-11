/**
 * @file MockPipe.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef PIPE_MOCK_H
#define PIPE_MOCK_H

#include "gmock/gmock.h"
#include "teflon/input/pipe/Pipe.h"

/**
 * Mock Pipe class.
 * 
 */
class MockPipe : public Pipe {
public:

    MockPipe() : Pipe() {
    }

    MockPipe(int const & compatibleType) : Pipe(compatibleType) {
    }

    MockPipe(vector< int > const & compatibleTypes) : Pipe(compatibleTypes) {
    }
private:

    virtual auto_ptr< Corpus > process(auto_ptr< Corpus > corpus) const {
        return corpus;
    }
};

#endif /* PIPE_MOCK_H */
