import sys
from collections import defaultdict

sys.stdin = open("revegetate.in", "r")
sys.stdout = open("revegetate.out", "w")
# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

n, m = map(int, sys.stdin.readline().split())

pastures = set(range(1, 1 + n))

graph = defaultdict(list)
for i in range(m):
    line = sys.stdin.readline().split()
    types = line[0]
    a, b = map(int, line[1:])
    graph[a].append((b, types))
    graph[b].append((a, types))


def dfs_search(start, graph):
    stack = [start]
    visited = set()
    visited.add(start)
    color = dict()
    color[start] = 1

    while stack:
        value = stack.pop()
        nodes = graph[value]

        for v in nodes:
            p, types = v
            if p not in visited:
                stack.append(p)
                visited.add(p)
                if types == 'S':
                    color[p] = color[value]
                elif types == 'D':
                    color[p] = color[value] ^ 1

            else:
                if types == 'S' and color[p] == color[value]:
                    continue
                elif types == 'D' and color[p] == color[value] ^ 1:
                    continue
                else:
                    return

    return visited


counter = 0
flag = True
while pastures:
    group = dfs_search(pastures.pop(), graph)
    if group is None:
        flag = False
        break
    counter += 1

    pastures -= group

if flag:
    print('1' + '0' * counter)
else:
    print(0)
