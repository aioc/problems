import random

N = int(input())
op2 = int(input())
seed = int(input())
random.seed(seed)
nums = set()
nums2 = set()

while len(nums) < N:
    nums.add(random.randint(1, 1000000000))

while len(nums2) < N:
    nums2.add(random.randint(1, 1000000000))

if not op2:
    print(N)
    for a, b in zip(nums, nums2):
        print(a, b)
else:
    print(N)
    n1 = list(nums)
    n2 = list(nums2)
    n1.sort()
    n2.sort()
    n3, n4 = [], []
    for x in n1:
        random.choice([n3, n4]).append(x)
    nx = list(zip(n3[::-1] + n4, n2))
    random.shuffle(nx)
    for a, b in nx:
        print(a, b)
