import random
import sys

if len(sys.argv) < 5:
    sys.stderr.write("Usage: python3 gen_random.py <N> <Q> <max letter value> <seed>\n")
    exit(0)

N = int(sys.argv[1])
Q = int(sys.argv[2])
max_a = int(sys.argv[3])
seed = int(sys.argv[4])
random.seed(seed)

print(N, Q)
overall = []
for _ in range(N):
    overall.append(random.randint(1, max_a))
print(" ".join(map(str, overall)))

for _ in range(Q):
    l, r = random.randint(1, N), random.randint(1, N)
    if l > r:
        l, r = r, l
    print(l, r)
