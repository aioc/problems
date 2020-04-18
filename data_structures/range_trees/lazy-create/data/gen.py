# Constraints
# N <= 1e9
# Q <= 1e5
# v_i <= 1e4
# 0 <= l_i <= r_i <= N-1

import random
import sys

N = int(sys.argv[1])
Q = int(sys.argv[2])
ops = sys.argv[3]
s = int(sys.argv[4])
random.seed(s)

print(N, Q)

for i in range(Q):
    op = random.choice(ops)
    l, r = random.randint(0, N-1), random.randint(0, N-1)
    if l > r:
        l, r = r, l
    if op == 'A' or op == 'S':
        v = random.randint(0, 10000)
        print(op, l, r, v)
    else:
        print(op, l, r)
