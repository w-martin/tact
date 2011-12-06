#! /bin/sh
# Counts the lines of code in this project (excluding included libraries).
# example usage: count_lines.sh ./src ./test ./include ./scripts --c
# example usage: count_lines.sh --c --d
#
defaultLocations="./src ./test ./include ./scripts"
locations=""
comments=""
for i in "$@"
do
    if [ "$i" == "--help" ]; then
        echo "\nUsage: count_lines.sh directory1 directory2...options"
        echo "Options:\n    --c Ignore comments\n    --d Default locations\n"
        exit
    elif [ "$i" == "--c" ]; then
    	comments="/^\s*#/d;/^\s*$/d;/^\s*\/\//d"
    elif [ "$i" == "--d" ]; then
    	locations="${locations} $defaultLocations"
    else
    	locations="${locations} $i"
    fi
done

( find $locations -type f -print0 | xargs -0 cat ) | sed "$comments" | wc -l
