#!/usr/bin/env python3
import os

# No randomness here

# Size, N, K
TEST_SETS = [(8, 20, 6), (8, 20, 20), (5, 1000, 1000), (5, 1000, 400), (10, 1000, 50), (8, 100000, 100000), (8, 100000, 15000), (5, 100000, 500)]
SUBTASKS = [(1, 16, [0, 1]), (2, 20, [0, 1, 2, 3, 4]), (3, 16, [1, 2]), (4, 29, [0, 1, 2, 3, 4]), (5, 19, [0, 1, 2, 3, 4, 5, 6, 7])]
#gen_file = open("gen/GEN", "w")
cnt = 0

for num, pts, groups in SUBTASKS:
    print("Subtask", num, "|", pts, "points")
    for gr in groups:
        cases, N, K = TEST_SETS[gr]
        for i in range(cases):
            os.system(f"echo \"{N} {K} {num} {69+i}\" | ./tkgen > st{num}_{cnt}.in")
            print("Generated case", cnt)
            cnt += 1
