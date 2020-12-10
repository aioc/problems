#!/bin/bash

# Compile generators
cd gen

echo "Compiling generators"

g++ -std=c++11 0-and-1.cpp -o ../0-and-1
g++ -std=c++11 random.cpp -o ../random
g++ -std=c++11 random-many-0s.cpp -o ../random-many-0s
g++ -std=c++11 all-same.cpp -o ../all-same


echo "Generating input"

cp handmade/* .

# Subtask 1

./random-dense 1 > sub1-random-dense.in
./random-lots-of-overlap 1 > sub1-random-lots-of-overlap.in
./lots-of-repetition 1 > sub1-lots-of-repetition.in

# Subtask 2

./random-dense 2 > sub2-random-dense.in
./random-lots-of-overlap 21 > sub2-random-lots-of-overlap-1.in
./random-lots-of-overlap 22 > sub2-random-lots-of-overlap-2.in
./lots-of-repetition 21 > sub2-lots-of-repetition-1.in
./lots-of-repetition 22 > sub2-lots-of-repetition-2.in

# Subtask 3

./random-dense 3 > sub3-random-dense.in
./random-lots-of-overlap 3 > sub3-random-lots-of-overlap.in
./lots-of-repetition 3 > sub3-lots-of-repetition.in

./sub3-interesting 1 > sub3-interesting-1.in
./sub3-interesting 2 > sub3-interesting-2.in

# Subtask 4

./random-dense 4 > sub4-random-dense.in
./random-lots-of-overlap 41 > sub4-random-lots-of-overlap-1.in
./random-lots-of-overlap 42 > sub4-random-lots-of-overlap-2.in
./random-lots-of-overlap 43 > sub4-random-lots-of-overlap-3.in
./random-lots-of-overlap 44 > sub4-random-lots-of-overlap-4.in
./random-lots-of-overlap 45 > sub4-random-lots-of-overlap-5.in
./lots-of-repetition 4 > sub4-lots-of-repetition.in

./sub4-use-long-umbrellas > sub4-use-long-umbrellas.in
./sub4-five-gaps > sub4-five-gaps.in
./sub4-1000-gaps > sub4-1000-gaps.in

# Subtask 5

./sub5-random-lots-of-overlap 1 > sub5-random-lots-of-overlap-1.in
./sub5-random-lots-of-overlap 2 > sub5-random-lots-of-overlap-2.in
./sub5-random-lots-of-overlap 3 > sub5-random-lots-of-overlap-3.in
./sub5-random-lots-of-overlap 4 > sub5-random-lots-of-overlap-4.in
./sub5-random-lots-of-overlap 5 > sub5-random-lots-of-overlap-5.in
./sub5-random-lots-of-overlap 6 > sub5-random-lots-of-overlap-6.in
./sub5-random-lots-of-overlap 7 > sub5-random-lots-of-overlap-7.in
./sub5-random-lots-of-overlap 8 > sub5-random-lots-of-overlap-8.in

./sub5-use-long-umbrella > sub5-use-long-umbrella.in

# Delete compiled generators.
rm lots-of-repetition
rm random-dense
rm random-lots-of-overlap
rm sub3-interesting
rm sub4-1000-gaps
rm sub4-five-gaps
rm sub4-use-long-umbrellas
rm sub5-random-lots-of-overlap
rm sub5-use-long-umbrella

echo "Finished generating input"