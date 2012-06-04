#!/usr/bin/env python3
##
# @file CreateClass.py
# @author William Martin <will.st4@gmail.com>
# @since 0.2
# 
# @section LICENSE
# 
# This file is part of mewt.
# 
# mewt is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# mewt is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with mewt.  If not, see <http://www.gnu.org/licenses/>.
# 
# @section DESCRIPTION
# 
# Creates a C++ class with the given version number and name.
# Places the:
# * header file in the appropriate include directory
# * source file in the appropriate source directory
# * test file in the appropriate test directory
# with the license and boilerplate code filled out based on a reference
# class.
#

import os, re, sys

##
# Prints the usage information.
#
def usage():
    print("Usage: CreateClass.py <name> <version> <reference> \
<include/project> <source> <test> \n\
    name: The name of the class i.e. myfolder/MyClass generates \
<include/project>/myfolder/MyClass.h <source>/myfolder/MyClass.cpp \
<test>/myfolder/MyClassTest.cpp \n\
    version: The version of the class i.e. 0.2 \n\
    reference: The source file to use as a reference for \
documentation, such as the license i.e. src/MyClass.cpp \n\
    include/project: The include directory, with any project name \
in use i.e. include/mewt src test \n\
    source: The source directory i.e. src \n\
    test: The test directory i.e. test or test/src")

if len(sys.argv) != 7:
    sys.exit(usage())
    
##
# Extracts the name of the class to create from the relative path name.
#
# @param name the relative path name of the class to create.
# @return the name of the class to create.
#
def extractClassName(name):
    matcher = re.compile("/")
    result = matcher.search(name)
    if (None == result):
        return name
    else:
        return name[result.end():]

name = sys.argv[1]
className = extractClassName(name)
version = sys.argv[2]
reference = sys.argv[3]
include = sys.argv[4]
source = sys.argv[5]
test = sys.argv[6]

print(className)
 
##
# Extracts a string template for the license from the reference file.
#
# @param reference the name of the reference file.
# @return a string template for the license from the reference file.
#
def extractTemplate(reference):
    template = []
    nameIndex = -1
    referenceFile = open(reference, "r")
    commentMatcher = re.compile("\s*/?\*")
    fileTagMatcher = re.compile(".*@file")
    versionTagMatcher = re.compile(".*@since")
    commentEnded = False
    while not commentEnded:
        line = referenceFile.readline()
        result = commentMatcher.match(line)
        if (None == result):
            commentEnded = True
        else:
            result = fileTagMatcher.match(line)
            if (None != result):
                line = line[:(result.end() + 1)] + className
                nameIndex = len(template)
            else:
                result = versionTagMatcher.match(line)
                if (None != result):
                    line = line[:(result.end() + 1):] + version + "\n"
            template.append(line)
    referenceFile.close()
    return (template, nameIndex)
    
try:
    template = extractTemplate(reference)
except IOError as e:
    sys.exit("Error. Reference '" + reference + "' does not exist.")

##
# Creates a file with the given name and creates its directory if
# it does not exist.
#
# @param filename the name of the file to create.
# @return the created file.
#
def createFile(filename):
    if os.path.exists(filename):
        raise IOError("Error. '" + filename + "' exists.")
    d = os.path.dirname(filename)
    if not ((0 == len(d)) or os.path.exists(d)):
        os.makedirs(d)
    f = open(filename, "w")
    print("Created " + filename)
    return f

SEPARATOR = '/'
headerExtension = ".h"
headerFileName = include + SEPARATOR + name + headerExtension
includeFileName = headerFileName[re.search("\s*include/", headerFileName).end():]
sourceExtension = ".cpp"
sourceFileName = source + SEPARATOR + name + sourceExtension
testExtension = "Test.cpp"
testFileName = test + SEPARATOR + name + testExtension
blankLine = "\n"

##
# Creates the header file.
#
# @param fileName the name of the file to create.
# @param className the name of the class to create.
# @param template the array of strings making the license template.
# @param fileTagIndex the index into the template of the file tag line.
# 
def createHeaderFile(fileName, className, template, fileTagIndex):
    f = createFile(fileName)
    i = 0
    while (i < len(template)):
        line = template[i]
        if (fileTagIndex == i):
            line = line + headerExtension + "\n"
        f.write(line)
        i += 1
    f.write(blankLine)
    upperCaseName = className.upper() + "_H"
    f.write("#ifndef " + upperCaseName + "\n\
#define " + upperCaseName + "\n")
    f.write(blankLine)
    f.write("class " + className + " {\npublic:\n\
    " + className + "();\n\
    " + className + "(" + className + " const & orig);\n\
    virtual ~" + className + "();\n};\n")
    f.write(blankLine)
    f.write("#endif /* " + upperCaseName + " */")
    f.write(blankLine)
    f.close()
   
##
# Creates the source file.
#
# @param fileName the name of the file to create.
# @param className the name of the class to create.
# @param includeFileName the name of the header file.
# @param template the array of strings making the license template.
# @param fileTagIndex the index into the template of the file tag line.
#  
def createSourceFile(fileName, className, includeFileName, template, fileTagIndex):
    f = createFile(fileName)
    i = 0
    while (i < len(template)):
        line = template[i]
        if (fileTagIndex == i):
            line = line + sourceExtension + "\n"
        f.write(line)
        i += 1
    f.write(blankLine)
    f.write("#include \"" + includeFileName + "\"\n")
    f.write(blankLine)
    f.write(className + "::" + className + "(){\n}\n")
    f.write(blankLine)
    f.write(className + "::" + className + "(" + className + " const & orig){\n}\n")
    f.write(blankLine)
    f.write(className + "::~" + className + "(){\n}")
    f.write(blankLine)
    f.close()
   
##
# Creates the test file.
#
# @param fileName the name of the file to create.
# @param className the name of the class to create.
# @param includeFileName the name of the header file.
# @param template the array of strings making the license template.
# @param fileTagIndex the index into the template of the file tag line.
#  
def createTestFile(fileName, className, includeFileName, template, fileTagIndex):
    f = createFile(fileName)
    i = 0
    while (i < len(template)):
        line = template[i]
        if (fileTagIndex == i):
            line = line + testExtension + "\n"
        f.write(line)
        i += 1
    f.write(blankLine)
    f.write("#include \"gtest/gtest.h\"\n#include \"" + includeFileName + "\"\n")
    f.write(blankLine)
    testName = className + "Test"
    instanceName = className.lower()
    f.write("namespace {\n\n\
    /**\n\
     * Tests " + className + ".\n\
     * \n\
     */ \n\
    class " + testName + " : public ::testing::Test {\n\
    protected:\n\n\
        " + testName + "() {\n\
            " + instanceName + " = new " + className + "();\n\
        }\n\n\
        virtual ~" + testName + "() {\n\
            delete " + instanceName + ";\n\
        }\n\
        " + className + " * " + instanceName + ";\n\
    };\n\n\
    /*\n\
     * Tests whether the copy constructor work correctly.\n\
     * \n\
     */\n\
    TEST_F(" + testName + ", CopyConstructorTest) {\n\
        " + className + " tmp(*" + instanceName + ");\n\
    }\n}")
    f.write(blankLine)
    f.close()

try:
    headerFile = createHeaderFile(headerFileName, className, template[0],
        template[1])
    sourceFile = createSourceFile(sourceFileName, className, includeFileName,
        template[0], template[1])
    testFile = createTestFile(testFileName, className, includeFileName,
        template[0], template[1])
except IOError as e:
    sys.exit(e)

