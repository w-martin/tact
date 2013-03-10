#!/bin/sh
find ../ -regex '.*\.\(cpp\|h\)$' -exec ./format.sh {} \;

