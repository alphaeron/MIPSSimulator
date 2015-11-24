#!/bin/bash

cat $1 | awk '{print $1;}' | awk 'NR>1{print $1}' RS=[ FS=]
