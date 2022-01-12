import sys

sys.stdin = open(r"C:\Users\Simian\OneDrive\CCC_senior_2021_2\test\test.in", "r")
N = int(sys.stdin.readline().strip())

east = {}
north = {}

for i in range(1, N + 1):
    d, x, y = sys.stdin.readline().strip().split()
    x, y = int(x), int(y)
    if d == 'E':
        east[i] = (x, y)
    elif d == 'N':
        north[i] = (x, y)

