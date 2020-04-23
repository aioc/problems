import random
import sys

if len(sys.argv) < 4:
    sys.stdout.write("Usage: python3 gen_incr.py <N> <Q> <seed>\n")
    exit(0)

N = int(sys.argv[1])
Q = int(sys.argv[2])
seed = int(sys.argv[3])

print(N, Q)
l = list(range(1, N+1))
print(" ".join(map(str, l)))
for i in range(Q):
    l, r = random.randint(1, N), random.randint(1, N)
    if l > r:
        l, r = r, l
    print(l, r)
