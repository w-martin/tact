#!/bin/bash
#
#######################################################################
# This file is part of tmte-cpp.
#
# tmte-cpp is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# tmte-cpp is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
#######################################################################
#
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
