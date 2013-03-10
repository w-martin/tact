/**
 * @file MockFeatureDocument.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.4
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
 * @section DESCRIPTION
 *
 * Mock FeatureDocument class.
 *
 */

#ifndef FEATURE_DOCUMENT_MOCK_H
#define FEATURE_DOCUMENT_MOCK_H

#include "gmock/gmock.h"
#include "teflon/input/corpus/feature/FeatureDocument.h"
#include "teflon/input/corpus/feature/MockFeatureMap.h"

class MockFeatureDocument : public FeatureDocument {
public:

  MockFeatureDocument() : FeatureDocument("MockFeatureDocument",
                                            auto_ptr< FeatureMap >(new MockFeatureMap())) {
  }

  MockFeatureDocument(MockFeatureDocument const & orig)
    : FeatureDocument(orig) {
  }

  virtual ~MockFeatureDocument() {
  }
};

#endif /* FEATURE_DOCUMENT_MOCK_H */
