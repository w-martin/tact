#!/usr/bin/env python
#
# File:   MockLayer.h
# Author: Will
# 
# Created on 05 July, 20:30
#
# Licensed under the BSD 2-Clause Licence.
# You may obtain a copy of the license at
# 
#     http://www.opensource.org/licenses/bsd-license.php
# 
# See COPYING for a copy of the License applied to this product.
# 

"""Driver for mocking a class with Google Mock with minimal effort."""

__author__ = 'will.st4@gmail.com (William Martin)'

import os
import sys

## Definitions
# Directories needed
headerDir = "include/nn-simulator/"
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
