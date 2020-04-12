#!/bin/bash

make -C ../validator all
cp ../validator/sub? .

validators=(sub1)


for val in ${validators[@]}; do
    echo "----------------"
    echo "Validating $val"
    echo "----------------"
    for input in *.in; do
        echo -n "Check $input "
        ./$val < $input
        if [[ $? -eq 0 ]]; then
            echo ""
        fi
    done
done

rm sub?
