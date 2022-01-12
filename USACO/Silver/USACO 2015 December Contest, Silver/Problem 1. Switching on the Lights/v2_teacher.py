import sys
from collections import defaultdict

sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')
#
# sys.stdin = open('lightson.in', 'r')
# sys.stdout = open('lightson.out', 'w')

data = [[int(i) for i in j.split()] for j in sys.stdin.read().strip().split('\n')]

n, m = data[0]

switch = defaultdict(set)
for x, y, a, b in data[1:]:
    switch[(x, y)].add((a, b))


def dfs_search(start):
    stack = [start]
    visited = set()
    visited.add(start)
    lighted = set()
    lighted.add(start)
    connected = set()
    connected.add(start)

    while stack:
        x, y = p = stack.pop()
        lighted.update(switch[p])
        rooms = {(x + 1, y),
                 (x - 1, y),
                 (x, y + 1),
                 (x, y - 1)}

        connected.update(rooms)

        nodes = ((switch[p] & connected) | (lighted & rooms)) - visited
        stack.extend(nodes)
        visited.update(nodes)

    return len(lighted)


print(dfs_search((1, 1)))
