#! /bin/sh
# Counts the lines of code in this project (excluding included libraries).

( find ./src ./test ./include -name '*.*' -print0 | xargs -0 cat ) | wc -l
