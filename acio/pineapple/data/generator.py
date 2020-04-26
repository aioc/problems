import os

def subtask(l, r, N, st):
    for i in range(l, r+1):
        op2 = 0
        if i == l:
            op2 = 1
        num = ("%3d" % i).replace(" ", "0")
        os.system("echo \'%d\n%d\n%d\' | python3 tcg.py > st%d_%s.in" % (N, op2, i ^ 3435, st, num))
        print("Generated %d" % i)

subtask(1, 40, 20, 1)
subtask(1, 10, 1000, 2)
subtask(1, 5, 300000, 3)
subtask(6, 15, 100000, 3)
