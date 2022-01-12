import sys
from collections import defaultdict

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')
sys.stdin = open('gates.in', 'r')
sys.stdout = open('gates.out', 'w')

n = int(sys.stdin.readline())
route = sys.stdin.readline()

graph = defaultdict(set)

# first fense
p_now = [(0, 0)]
if route[0] == 'N':
    p_now.append((0, 1))
elif route[0] == 'S':
    p_now.append((0, -1))
elif route[0] == 'W':
    p_now.append((-1, 0))
elif route[0] == 'E':
    p_now.append((1, 0))

graph[p_now[-2]].add(p_now[-1])
  

# Rest fenses
for i in range(1, n):
    types = route[i]
    x, y = p_now[-1]
    if types == 'N':
        p_now.append((x, y+1))
    elif types == 'S':
        p_now.append((x, y-1))
    elif types == 'W':
        p_now.append((x-1, y))
    elif types == 'E':
        p_now.append((x+1, y))

    graph[p_now[-2]].add(p_now[-1])

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

print(dfs_search(graph, (0, 0)))
