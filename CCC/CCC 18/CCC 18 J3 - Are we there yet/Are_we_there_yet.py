import sys

d = map(int, sys.stdin.readline().strip().split())


def solve(d):
    p = [0]
    for j in d:
        p.append(p[-1] + j)

    for i in range(5):
        for j in range(5):
            ans = abs(p[i]-p[j])
            print(ans, end=' ')
        print()


ans_l = solve(d)

