/**
 * @file MockDocument.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "gmock/gmock.h"
#include "tmte-cpp/model/Document.h"

/**
 * Mock Document class.
 * 
 */
class MockDocument : public Document {
public:

    MockDocument() : Document(0) {
    }
};
