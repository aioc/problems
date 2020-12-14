#!/bin/bash

g++ gen-case.cpp -o gen-case
g++ gen-balanced.cpp -o gen-balanced

echo 1 1 1 1 | ./gen-case > 1-1-lo.in
echo 20 5 1 100000 | ./gen-case > 20-5-wide.in
echo 80 4 80000 100000 | ./gen-case > 80-4-narrow.in
echo 100 3 1 100000 | ./gen-case > 100-3-wide.in
echo 1000 2 80000 100000 | ./gen-case > 1000-2-narrow.in
echo 100000 1 100000 100000 | ./gen-case > 100000-1-hi.in
echo 100000 100000 90000 100000 | ./gen-case > 100000-100000-narrow.in

echo 97 33 2000 5000 | ./gen-case > 97-33-wide.in
echo 97 36 2000 2500 | ./gen-case > 97-36-narrow.in
echo 100 49 2000 3000 | ./gen-case > 100-49-narrow.in
echo 100 57 2000 10000 | ./gen-case > 100-57-wide.in

echo 2000 500 1 100000 | ./gen-case > 2000-500-wide.in
echo 2000 500 80000 100000 | ./gen-case > 2000-500-narrow.in
echo 4000 1000 1 100000 | ./gen-case > 4000-1000-wide.in
echo 4000 1000 80000 100000 | ./gen-case > 4000-1000-narrow.in
echo 8000 2000 1 100000 | ./gen-case > 8000-2000-wide.in
echo 8000 2000 80000 100000 | ./gen-case > 8000-2000-narrow.in
echo 10000 2500 1 100000 | ./gen-case > 10000-2500-wide.in
echo 10000 2500 80000 100000 | ./gen-case > 10000-2500-narrow.in

echo 597 72 1 9999 | ./gen-case > 597-72-wide.in
echo 978 48 200 9999 | ./gen-case > 978-48-wide.in

echo 100 30 9001 | ./gen-balanced > 100-30-perfect.in
echo 1000 300 666 | ./gen-balanced > 1000-300-perfect.in
echo 6000 2000 31337 | ./gen-balanced > 6000-2000-perfect.in
echo 99999 99999 89898 | ./gen-balanced > 999990-99999-perfect.in

echo 91842 9182 1 9999 | ./gen-case > 918421-99182-wide.in


# A couple 1000 cases
# Small K
echo 1000 30 1 230 | ./gen-case > sub4-1.in
# Large K
echo 1000 900 1 230 | ./gen-case > sub4-2.in
# Medium K
echo 1000 300 3 10 | ./gen-case > sub4-3.in


# K = 2 cases
echo 100000 2 3 10 | ./gen-case > K2-1.in
echo 100000 2 1 100000 | ./gen-case > K2-2.in
echo 100000 2 99000 100000 | ./gen-case > K2-3.in
echo 100000 2 3333 3333 | ./gen-case > K2-4.in
echo 2 2 99000 100000 | ./gen-case > K2-5.in
echo 2 2 1 1 | ./gen-case > K2-6.in

# K = 3 cases
echo 100000 3 30 70 | ./gen-case > K3-1.in
echo 100000 3 1 100000 | ./gen-case > K3-2.in
echo 100000 3 55 58 | ./gen-case > K3-3.in
echo 3 3 1 10 | ./gen-case > K3-4.in
echo 6 3 1 10 | ./gen-case > K3-5.in
echo 11 3 1 10 | ./gen-case > K3-6.in

g++ sol.cpp -o sol
echo Generating output files...
for i in *.in; do
	echo ${i/.in}...
	./sol < $i > ${i/.in/.out}
done
rm sol
rm gen-case gen-balanced
