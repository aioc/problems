#!/bin/bash

g++ checker.cpp -std=c++11 -o check
 
for i in *.in; do 
    ./check < $i; 
    if [ $? -eq 1 ]
    then 
        echo "FAIL $i"; 
    else 
        echo "SUCCESS $i"; 
    fi
done

rm check
