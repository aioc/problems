#!/bin/bash

g++ checker.cpp -std=c++11 -o check
 
for i in *.in; do 
    ./check < $i
    if [[ $? != 0 ]]
    then 
        echo "FAIL $i"; 
    else 
        echo "SUCCESS $i"; 
    fi
done

rm check
