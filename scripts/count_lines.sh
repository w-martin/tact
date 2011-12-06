#! /bin/sh
# Counts the lines of code in this project (excluding included libraries).

( find ./src ./test ./include ./scripts -name '*.*' -print0 | xargs -0 cat ) | sed '/^\s*#/d;/^\s*$/d;/^\s*\/\//d' | wc -l
