/**
 * @file Files.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
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

#include "mewt/util/Files.h"

#include <fstream>
#include <streambuf>

using std::ifstream;
using std::ios;
using std::istreambuf_iterator;

auto_ptr< string > mewt::util::files::readFile(const string & location) {
    ifstream t(location.c_str());

    t.seekg(0, ios::end);
    int const length = t.tellg();
    t.seekg(0, ios::beg);

    auto_ptr< string > text = auto_ptr< string > (new string());
    text->reserve(length);
    text->assign(istreambuf_iterator< char >(t), istreambuf_iterator< char >());
    t.close();

    return text;
}

void mewt::util::files::appendFile(string const & text,
        string const & filename) {
    std::ofstream outputFileStream;
    outputFileStream.open(filename.c_str(), std::ios_base::app);
    outputFileStream << text << std::endl;
    outputFileStream.close();
}
