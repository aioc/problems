#!/bin/bash

g++ checker.cpp -std=c++11 -o check
 
for i in *.in; do 
    echo $i;
    ./check < $i; 
done

rm check
