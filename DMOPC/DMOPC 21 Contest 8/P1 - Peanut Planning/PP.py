import bisect
from collections import Counter, defaultdict
from sys import stdin, stdout

input = stdin.readline
N, M = (int(x) for x in input().split())
data_in = sorted([int(x) for x in input().split()])
ans = []
d = dict()


def dicToList(d: dict):
    return (list(d))


def counterMinusOne(d: Counter, x: int):
    d[x] -= 1
    if (d[x] == 0):
        del d[x]


for i in data_in:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1

while(len(d)):
    data = dicToList(d)
    t1 = data[0]
    t2 = M - t1
    ans.append(t1)
    counterMinusOne(d, t1)
    data = dicToList(d)
    pos = bisect.bisect_left(data, t2)
    if pos != len(data):
        ans.append(data[pos])
        counterMinusOne(d, data[pos])
    else:
        break
if len(ans) == N:
    print(*ans)
else:
    print(-1)
