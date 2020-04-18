#!/bin/bash

# - trivial cases
#     - one building with main
#     - no mains at all
# - random max cases
# - complexity enforcement (max cases)
#     - 10k initial mains, connect stuff to them before connecting together
#     - 100k initial mains, connect stuff to them before connecting together
# - union find enforcement
#     - alternate connecting stuff to mains and joining mains, joining randomly
#     - create chains not connected to a main before joining them randomly
# - break basic tree depth heuristics
#     - create long chains/trees with few branches, join by distant leaves & middle

rm *.in *.out

make gen-random
make gen-chains

# ./gen-random N pipeInstalls mainInstalls checks seed

# one building with a main
./gen-random 10 20 1 20 72839 > 1.in

# duplicate mains and pipes (by pigeonhole principle)
./gen-random 10 150 13 50 72840 > 2.in

# no mains
./gen-random 21 47 0 100 72841 > 3.in

# empty case :D
./gen-random 1 0 0 1 1 > 4.in

# max cases of varying density
./gen-random 1000000 49999 1 50000 94 > max1.in
./gen-random 1000000 49980 20 50000 95 > max2.in
./gen-random 1000000 49500 500 50000 96 > max3.in
./gen-random 1000000 40000 10000 50000 97 > max4.in
./gen-random 1000000 10000 80000 10000 98 > max5.in

# dense cases
./gen-random 1000 50000 2 49998 201 > dense1.in
./gen-random 1000 50000 100 49900 202 > dense2.in
./gen-random 1000 50000 500 49500 203 > dense3.in

# ./gen-chains n chains mainsDuring mainsAfter joinsDuring joinsAfter checksDuring checksAfter seed

# one long chain
./gen-chains 50000 1  1 1  0 0  10000 10000  15364 > chain1.in

# √n chains, few mains, √n joins
./gen-chains 50000 223  2 2  200 200  20000 20000  15365 > chain2.in

# √n chains, few mains, many joins
./gen-chains 50000 224  1 1  5000 5000  20000 20000  15366 > chain3.in

# √n chains, many mains, few joins
./gen-chains 50000 222  5000 5000  300 300  19000 18000  15367 > chain4.in

# √n chains, many mains, many joins
./gen-chains 50000 222  3000 3000  3000 3000  18000 17000  15368 > chain5.in

# √n chains, no mains
./gen-chains 70000 225  0 0  234 243  15000 14000  15369 > chain6.in

# √n chains, one main after
./gen-chains 70000 225  0 1  5000 4000  10000 10000  15370 > chain7.in

# √n chains, one main after, only query after
./gen-chains 70000 225  0 1  5000 4000  0 20000  15371 > chain8.in

