/**
 * @file FeatureDocument.h
 * @author  William Martin <will.st4@gmail.com>
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

#ifndef FEATUREDOCUMENT_H
#define	FEATUREDOCUMENT_H
#define DOCUMENT_TYPE_FEATURE 2

#include "mewt/input/corpus/Document.h"
#include "mewt/input/corpus/feature/FeatureMap.h"
#include <memory>

using std::auto_ptr;

/**
 * FeatureDocument class for corpus files. Stores the name of the file.
 * 
 */
class FeatureDocument : public Document {
public:
    /**
     * Default constructor.
     * 
     * @param name the name of the file.
     * 
     */
    FeatureDocument(string const name, auto_ptr< FeatureMap > featureMap);
    /**
     * Copy constructor.
     * 
     * @param orig the FeatureDocument to copy.
     * 
     */
    FeatureDocument(const FeatureDocument& orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~FeatureDocument();
    /**
     * Checks if this Document is equal to the other Document.
     * 
     * @param other the Document to check against.
     * @return true if this Document is equal to the other Document,
     * false otherwise.
     * 
     */
    virtual bool const equals(Document const & other) const;
    /**
     * Gets the text from this FeatureDocument.
     * 
     * @return the text from this FeatureDocument.
     * 
     */
    FeatureMap * const getFeatureMap() const;
    /**
     * Gets the type of this Document.
     * 
     * @return the type of this Document.
     * 
     */
    virtual int const getType() const;
private:
    auto_ptr< FeatureMap > featureMap;
};

#endif	/* FEATUREDOCUMENT_H */
