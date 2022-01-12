import sys

n = int(sys.stdin.readline())
line = sys.stdin.readline().strip()

count_A = line.count('A')
count_B = n - count_A
if count_B > count_A:
    print("B")
elif count_A > count_B:
    print('A')
else
    print('Tie')