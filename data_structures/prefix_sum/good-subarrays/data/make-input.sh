#!/bin/bash

# Compile generators
cd gen

echo "Compiling generators"

g++ -std=c++11 0-and-1.cpp -o ../0-and-1
g++ -std=c++11 random.cpp -o ../random
g++ -std=c++11 random-many-0s.cpp -o ../random-many-0s
g++ -std=c++11 all-same.cpp -o ../all-same

cd ../

echo "Generating input"

cp handmade/* .

# n <= 1000
./0-and-1 1000 0 > sub1-0-and-1.in
./random 1000 > sub1-random.in
./random-many-0s 999 > sub1-random-many-0s-1.in
./random-many-0s 1000 > sub1-random-many-0s-2.in
./all-same 1000 0 > sub1-all0.in
./all-same 1000 1 > sub1-all1.in
./all-same 1000 9 > sub1-all9.in

# 0 or 1

./0-and-1 100000 0 > 0-and-1-1.in
./0-and-1 100000 1 > 0-and-1-2.in
./0-and-1 100000 2 > 0-and-1-2.in

# full

./random 100000 > random.in
./random-many-0s 100000 > random-many-0s.in
./all-same 100000 0 > all0.in
./all-same 100000 1 > all1.in
./all-same 100000 9 > all9.in

# Delete compiled generators

rm 0-and-1
rm random
rm random-many-0s
rm all-same

echo "Finished generating input"