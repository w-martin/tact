/**
 * @file RandomNumberGenerator.h
 * @author William Martin <will.st4@gmail.com>
 * @since 0.1
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

#ifndef RANDOMNUMBERGENERATOR_H
#define	RANDOMNUMBERGENERATOR_H

/**
 * Generates pseudorandom numbers with a given seed, such that they can be
 * reconstructed if necessary.
 * 
 */
class RandomNumberGenerator {
public:
    /**
     * Default constructor. Uses the current time as the seed.
     * 
     */
    RandomNumberGenerator();
    /**
     * Specific constructor.
     * 
     * @param seed the seed to use for pseudorandom number generation.
     * 
     */
    RandomNumberGenerator(int const seed);
    /**
     * Copy constructor.
     * 
     * @param orig the original RandomNumberGenerator.
     * 
     */
    RandomNumberGenerator(const RandomNumberGenerator& orig);
    /**
     * Default destructor.
     * 
     */
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
     * Returns a pseudorandom double in the range 0 to 1 sampled uniformly from 
     * that range. 
     * mean = 0.5
     * variance = 1/12
     * 
     * @return a random double.
     * 
     */
    double const nextUniform();
private:
    /**
     * The number of numbers that have been generated.
     * 
     */
    int count;
    /**
     * The seed that is used for pseudorandom number generation.
     * 
     */
    int seed;
};

#endif	/* RANDOMNUMBERGENERATOR_H */
