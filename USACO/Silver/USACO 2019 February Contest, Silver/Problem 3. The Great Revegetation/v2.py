import sys
from collections import defaultdict

sys.stdin = open("revegetate.in", "r")
sys.stdout = open("revegetate.out", "w")
# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

n, m = map(int, sys.stdin.readline().split())

pastures = set(range(1, 1 + n))


def default():
    return [set(), set()]


graph = defaultdict(default)
for i in range(m):
    line = sys.stdin.readline().split()
    types = line[0]
    a, b = map(int, line[1:])
    if types == 'S':
        graph[a][0].add(b)
        graph[b][0].add(a)
    else:
        graph[a][1].add(b)
        graph[b][1].add(a)


def dfs_search(start, graph):
    stack = [start]
    visited = set()
    visited.add(start)
    color = dict()
    color[start] = 1

    while stack:
        value = stack.pop()
        nodes_S, nodes_D = graph[value]

        for v in nodes_S:
            if v not in visited:
                stack.append(v)
                visited.add(v)
                color[v] = color[value]

            else:
                if color[v] == color[value]:
                    continue
                else:
                    return

        for v in nodes_D:
            if v not in visited:
                stack.append(v)
                visited.add(v)
                color[v] = color[value] ^ 1

            else:
                if color[v] == color[value] ^ 1:
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
