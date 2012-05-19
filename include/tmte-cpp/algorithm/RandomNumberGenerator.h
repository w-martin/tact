/**
 * @file RandomNumberGenerator.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 *  * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef RANDOMNUMBERGENERATOR_H
#define	RANDOMNUMBERGENERATOR_H

class RandomNumberGenerator {
public:
    RandomNumberGenerator();
    RandomNumberGenerator(int const seed);
    RandomNumberGenerator(const RandomNumberGenerator& orig);
    virtual ~RandomNumberGenerator();
    /**
     * Gets the count of the number of times rand has been called.
     * 
     * @return the count of the number of times rand has been called.
     * 
     */
    int const getCount() const;
    /**
     * Gets the seed that this RandomNumberGenerator was created with.
     * 
     * @return the seed that this RandomNumberGenerator was created with.
     * 
     */
    int const getSeed() const;
    /**
     * Returns a random double in the range 0 to 1 sampled uniformly from 
     * that range. 
     * mean = 0.5
     * variance = 1/12
     * 
     * @return a random double.
     * 
     */
    double const nextUniform();
private:
    int count;
    int seed;
};

#endif	/* RANDOMNUMBERGENERATOR_H */

