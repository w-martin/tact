/**
 * @file InputOptimiseBundle.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "mewt/input/pipe/bundle/InputOptimiseBundle.h"
#include "mewt/input/pipe/InputPipe.h"
#include "mewt/input/pipe/XmlFilter.h"
#include "mewt/input/pipe/PunctuationFilter.h"
#include "mewt/input/pipe/FeatureMapPipe.h"
#include "mewt/input/pipe/LowerCasePipe.h"

using namespace mewt::input::pipe::bundle;

InputOptimiseBundle::InputOptimiseBundle()
: Pipe(DOCUMENT_TYPE_BASIC) {
  attachPipe(auto_ptr< Pipe > (new InputPipe()));
  attachPipe(auto_ptr< Pipe > (new XmlFilter()));
  attachPipe(auto_ptr< Pipe > (new FeatureMapPipe()));
  attachPipe(auto_ptr< Pipe > (new LowerCasePipe()));
  attachPipe(auto_ptr< Pipe > (new PunctuationFilter()));
}

InputOptimiseBundle::~InputOptimiseBundle() {
}

auto_ptr< Corpus > InputOptimiseBundle::process(
        auto_ptr<Corpus> corpus) const {
  return corpus;
}
