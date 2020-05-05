#!/bin/bash

# Go to gen file
cd gen/

# Compile generators
for i in *.cpp; do
    g++ -std=c++11 $i -o ../${i%.cpp} -O2
done

cd ..

rm *.in *.out

# Copy out handmade cases
cp static/* .

seed=8422

for i in `seq 4 15`; do
    ./gen-random $i $((++seed))
done

./gen-diag 15 10 11 1 $((++seed))
./gen-diag 15 10 11 0 $((++seed))
./gen-diag 15 100 100 1 $((++seed))

rm gen-random
rm gen-diag
