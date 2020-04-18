#!/bin/bash

# Go to gen file
cd gen/

# Compile generators
for i in *.cpp; do
    g++ -std=c++11 $i -o ../${i%.cpp} -O2
done

cd ..

rm *.in *.out

hun=$((10**5))
bil=$((10**9))
seed=29239

cat > sample.in <<- eof
30 4
1 10 19
1 15 24
3 5 25
4 1 30
eof

# Max case
cat > max.in <<- eof
1000000000 1
1000000000 1 1000000000
eof


# N = 1e9, random queries where d in [1, 1e9]
./gen-random $bil $hun 1 $bil $((++seed))
# N = 1e9, random queries where d in [1, 1000]
./gen-random $bil $hun 1 1000 $((++seed))
# N = 1e9, random queries where d in [1, 10]
./gen-random $bil $hun 1 10 $((++seed))
# N = 1e9, random queries where d in [1e9-30, 1e9]
./gen-random $bil $hun $((10**9-30)) $bil $((++seed))
# N = 1e9, random queries where d in [1e9, 1e9]
./gen-random $bil $hun $bil $bil $((++seed))
# N = 1, random queries where d in [1, 1e9]
./gen-random 1 $hun 1 $bil $((++seed))
# N = 50, random queries where d in [1, 49]
./gen-random 50 $hun 1 49 $((++seed))
# N = 10, random queries, where d in [1,49]
./gen-random 10 100000 1 10 $((++seed))

# N = 2^29, random queries where d in [1, 1e9]
./gen-random $((2**29)) $hun 1 $bil $((++seed))
# N = 2^29, random queries where d in [1, 50]
./gen-random $((2**29)) $hun 1 50 $((++seed))

# N = 2^29-1, random queries where d in [1, 1e9]
./gen-random $((2**29-1)) $hun 1 $bil $((++seed))
# N = 2^29-1, random queries where d in [1, 50]
./gen-random $((2**29-1)) $hun 1 50 $((++seed))

# N = 2^29+1, random queries where d in [1, 1e9]
./gen-random $((2**29+1)) $hun 1 $bil $((++seed))
# N = 2^29+1, random queries where d in [1, 50]
./gen-random $((2**29+1)) $hun 1 50 $((++seed))

# N = 1e9, random queries where d in [1, 1e9] and query ranges have sizes in [1, 100]
./gen-size $bil $hun 0 $bil 1 100 $((++seed))
# N = 1e9, random queries where d in [1, 1e9] and query ranges have sizes in [1e9-50, 1e9]
./gen-size $bil $hun 0 $bil $((bil-50)) $bil $((++seed))
