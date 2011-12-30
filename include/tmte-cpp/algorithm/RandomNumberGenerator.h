/**
 * @file RandomNumberGenerator.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
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

