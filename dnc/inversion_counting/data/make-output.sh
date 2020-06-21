#!/bin/bash

echo "Compiling judge solutions..."

declare -a soln
for i in ../solutions/*-full.cpp; do
    exe=`basename $i`
    exe=${exe%.cpp}
    g++ $i -std=c++11 -o $exe
    if [ $? -ne 0 ]; then
        echo "$exe did not compile..."
    else
        soln+=($exe)    
    fi
done

echo "Done"

echo "Generating output files and/or testing judge solutions"

for sol in ${soln[@]}; do
    echo "-------------------"
    echo "Testing $sol"
    echo "-------------------"
    for input in *.in; do
        output=${input%in}out

        if [ -e $output ]; then
            
            echo -n "Test $input "
            ./$sol < $input > temp
            diff -b temp $output > /dev/null
            if [ $? -eq 0 ]; then
                echo "correct"
            else
                echo "incorrect"
                #diff -b temp $output
            fi
        else
        
            echo "$output does not exist. Generating it now..."
            ./$sol < $input > $output
            if [ $? -ne 0 ]; then
                rm $output
            fi
        fi
    done
done

for sol in ${soln[@]}; do
    rm $sol
done

if [ -e temp ]; then
    rm temp
fi
