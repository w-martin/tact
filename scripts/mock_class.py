#!/usr/bin/env python

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
