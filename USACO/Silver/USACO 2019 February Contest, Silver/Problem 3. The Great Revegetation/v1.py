import sys
from collections import defaultdict, deque

# sys.stdin = open("revegetate.in", "r")
# sys.stdout = open("revegetate.out", "w")
sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')


def dfs_search(start, graph):
    stack = []
    stack.append(start)
    visited_a = set()
    visited_a.add(start)
    visited_b = set()
    add_two = False

    while stack:
        value = stack.pop()
        nodes = graph[value]
        # if all(nodes):
        #     add_two = True
        for v1 in nodes[0]:
            if v1 not in visited_a:
                stack.append(v1)
                visited_a.add(v1)
        for v2 in nodes[1]:
            if v2 not in visited_b:
                stack.append(v2)
                visited_b.add(v2)

    # if add_two:
    #     return 2
    # else:
    return visited

n, m = map(int, sys.stdin.readline().split())

def default():
    return [set(), set()]

colors = defaultdict(default)
print(colors[1])
for i in range(m):
    line = sys.stdin.readline().split()
    types = line[0]
    a, b = map(int, line[1:])
    if types == 'S':
        colors[a][0].add(b)
        colors[b][0].add(a)
    else:
        colors[a][1].add(b)
        colors[b][1].add(a)

print(colors)