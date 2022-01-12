import sys

sys.stdin = open(r"C:\Users\Simian\OneDrive\CCC_senior_2021_2\test\test.in", "r")
N = int(sys.stdin.readline().strip())
east = {}
north = {}
ans = []

for i in range(1, N + 1):
    d, x, y = sys.stdin.readline().strip().split()
    x, y = int(x), int(y)
    if d == 'E':
        east[(x, y)] = i
    elif d == 'N':
        north[(x, y)] = i

for e, order in east.items():
    avail = tuple(n[0] for n in north if n[0] - e[0] > e[1] - n[1] > 0)
    if avail:
        closest_d = min(avail)
        ans.append((order, closest_d))

    else: ans.append((order, "infinity"))
    
print(ans)