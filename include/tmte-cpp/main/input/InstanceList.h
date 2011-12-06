/**
 * @file InstanceList.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef INSTANCELIST_H
#define	INSTANCELIST_H

#include "tmte-cpp/main/input/Pipe.h"
#include "tmte-cpp/main/input/Instance.h"
#include <memory>

using std::auto_ptr;

/**
 * List of instances for use with Pipe.
 * 
 */
class InstanceList {
public:

    InstanceList();

    InstanceList(const InstanceList& orig);

    virtual ~InstanceList();
    /**
     * Gets the Instance objects.
     * 
     * @return the Instance objects.
     * 
     */
    vector<Instance> const * const getInstances() const;
    /**
     * Adds the given Instance to this InstanceList.
     * 
     * @param instance the Instance to add.
     * @return true if the Instance was added successfully, false otherwise.
     * 
     */
    bool const addInstance (Instance const & instance);
private:
    auto_ptr<Pipe> pipe;
    vector<Instance> * instances;
};

#endif	/* INSTANCELIST_H */
