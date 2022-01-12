import sys
from collections import defaultdict

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')
sys.stdin = open('gates.in', 'r')
sys.stdout = open('gates.out', 'w')

n = int(sys.stdin.readline())
route = sys.stdin.readline()

graph = defaultdict(set)
# complex number trying
p_now = 0
prev = 0
if route[0] == 'N':
    p_now += 1j
elif route[0] == 'S':
    p_now -= 1j
elif route[0] == 'W':
    p_now -= 1
elif route[0] == 'E':
    p_now += 1

graph[prev].add(p_now)
prev = p_now

for i in range(1, n):
    types = route[i]
    if types == 'N':
        p_now += 1j
    elif types == 'S':
        p_now -= 1j
    elif types == 'W':
        p_now -= 1
    elif types == 'E':
        p_now += 1

    graph[prev].add(p_now)
    prev = p_now

def dfs_search(graph, p):
    stack = []
    stack.append(p)
    visited = set()
    visited.add(p)
    fence = set()
    cycle = 0

    while stack:
        value = stack.pop()
        nodes = graph[value]
        for v in nodes:
            fence.add((value, v))
            if v not in visited:
                stack.append(v)
                visited.add(v)
            elif (v, value) not in fence:
                cycle += 1

    return cycle



print(dfs_search(graph, 0))
