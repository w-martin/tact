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

#include <vector>
#include "tmte-cpp/main/input/Instance.h"

using std::vector;

/**
 * Pipe class for transforming Instance objects.
 * 
 */
class Pipe : vector<Instance> {
public:

    Pipe() {
    }

    Pipe(const Pipe& orig) {
    }

    virtual ~Pipe() {
    }
private:
};

#endif	/* PIPE_H */
