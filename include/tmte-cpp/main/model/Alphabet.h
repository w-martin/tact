/**
 * @file Alphabet.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef ALPHABET_H
#define	ALPHABET_H



/**
 * Represents a finite collection of words.
 * 
 */
class Alphabet {
public:
    Alphabet();
    Alphabet(const Alphabet& orig);
    virtual ~Alphabet();
    /**
     * Gets the size of this Alphabet.
     * 
     * @return the size of this Alphabet.
     * 
     */
    virtual const int getSize() const;
    virtual const int lookupIndex(const & const au)
private:

};

#endif	/* ALPHABET_H */

