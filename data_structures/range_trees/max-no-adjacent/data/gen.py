#!/usr/bin/python3

import sys
import random

if len(sys.argv) != 5:
    sys.stderr.write("Flags: <N> <B> <mode> <seed>\n")
    sys.exit(1)

N = int(sys.argv[1])
B = int(sys.argv[2])
mode = sys.argv[3]

#random.seed(int(sys.argv[4]))

print(N, B)

A = [str(random.randint(1, 10000)) for x in range(N)]

print(" ".join(A))

for i in range(B):
    if random.randint(1, 2) == 1:
        op = 'Q'
        p1 = random.randint(1, N)
        p2 = random.randint(1, N)
        if p1 > p2:
            p1, p2 = p2, p1
    else:
        op =  'U'
        if mode == 'random':
            p1 = random.randint(1, N)
        elif mode == 'sequential':
            p1 = i+1
        else:
            sys.stderr.write("Invalid mode\n")
            sys.exit(1)
        p2 = random.randint(1, 10000)
    print(op, p1, p2)
