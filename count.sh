#!/bin/bash

cat $1 | awk '{ print $3; }' | sort - | uniq -c -
