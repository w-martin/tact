#!/usr/bin/env python
"""
@file mock_class.py
@author  William Martin <will.st4@gmail.com>
@since 0.0

@section LICENSE

This file is part of tmte-cpp.

tmte-cpp is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

tmte-cpp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.

@section DESCRIPTION
This is a script to create a mock class.
"""

__author__ = 'will.st4@gmail.com (William Martin)'

import os
import sys

## Definitions
# Directories needed
headerDir = "include/tmte-cpp/"
mainDir = headerDir + "main/"
testDir = headerDir + "test/"
# gmock script
gmockScript = "gmock-1.6.0/scripts/generator/gmock_gen.py"
# function
def usage():
    print("Usage:\n    scripts/mock_class.py header.h\nThe generated Mock class will be placed in the include/nn-simulator/test directory.")
def fileAbsent(fileName):
    print("Error. File '" + fileName + "' does not exist.")

if len(sys.argv) > 1:
    source = sys.argv[1]
    if not (mainDir in source):
        source = mainDir + source
    if os.path.isfile(source):
        try:
            open(source)
            dest = source.replace(mainDir, testDir)
            className = source[source.rindex('/')+1:source.rindex('.')]
            dest = dest[:source.rindex('/')+1] + "Mock" + className + ".h"
            command = gmockScript + " " + source + " " + className + " >> " + dest
            #print command
            os.popen(command)
        except IOError:
            fileAbsent(source)
    else:
        fileAbsent(source)
else:
    usage()
