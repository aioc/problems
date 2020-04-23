import random
import sys

# Generates palindromic blocks

if len(sys.argv) < 6:
    sys.stderr.write("Usage: python3 gen_blocks.py <N> <Q> <block min> <block max> <seed>\n")
    exit(0)

N = int(sys.argv[1])
Q = int(sys.argv[2])
blockmin = int(sys.argv[3])
blockmax = int(sys.argv[4])
seed = int(sys.argv[5])

random.seed(seed)

sofar = 0
overall = []
blocks = []
ints = { 1 }
def getnumber():
    res = 1
    while res in ints:
        res = random.randint(1, 123454321)
    ints.add(res)
    return res

print(N, Q)
while sofar < N:
    sz = min(N-sofar, random.randint(blockmin, blockmax))
    l = sofar + 1
    r = sofar + sz
    sofar += sz
    blocks.append((l, r))
    elems = []
    if sz & 1:
        elems.append(1)
    for _ in range(sz // 2):
        x = getnumber()
        elems.append(x)
        elems.append(x)
    assert(len(elems) == sz)
    random.shuffle(elems)
    for x in elems:
        overall.append(x)

assert(len(overall) == N)
print(" ".join(map(str, overall)))

for _ in range(Q):
    code = random.randint(1, 8)
    if code <= 6:
        (l1, r1), (l2, r2) = random.sample(blocks, 2)
        if l1 > r2:
            l1, r2 = l2, r1
        if code == 1 and l1 > 1:
            print(l1-1, r2)
        elif code == 2 and r2 < N:
            print(l1, r2+1)
        else:
            print(l1, r2)
    else:
        l, r = random.randint(1, N), random.randint(1, N)
        if l > r:
            l, r = r, l
        print(l, r)
