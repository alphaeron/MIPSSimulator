#!/bin/bash

cat $1 | awk '{ s = ""; for (i = 3; i <= NF; i++) s = s $i " "; print s }' | cut -d ';' -f 1 - | cut -d '[' -f 1 -
