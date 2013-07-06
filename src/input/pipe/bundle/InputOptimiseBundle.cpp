/**
 * @file InputOptimiseBundle.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "tact/input/pipe/bundle/InputOptimiseBundle.h"
#include "tact/input/pipe/InputPipe.h"
#include "tact/input/pipe/XmlFilter.h"
#include "tact/input/pipe/PunctuationFilter.h"
#include "tact/input/pipe/FeatureMapPipe.h"
#include "tact/input/pipe/LowerCasePipe.h"

InputOptimiseBundle::InputOptimiseBundle()
  : Pipe(DOCUMENT_TYPE_BASIC) {
  attachPipe(auto_ptr< Pipe >(new InputPipe()));
  attachPipe(auto_ptr< Pipe >(new XmlFilter()));
  attachPipe(auto_ptr< Pipe >(new FeatureMapPipe()));
  attachPipe(auto_ptr< Pipe >(new LowerCasePipe()));
  attachPipe(auto_ptr< Pipe >(new PunctuationFilter()));
}

InputOptimiseBundle::~InputOptimiseBundle() {
}

auto_ptr< Corpus > InputOptimiseBundle::process(
  auto_ptr<Corpus> corpus) const {
  return corpus;
}
