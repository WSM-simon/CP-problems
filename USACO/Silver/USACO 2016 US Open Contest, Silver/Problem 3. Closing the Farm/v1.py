from collections import deque, defaultdict
import sys


def bfs_search(start, graph):
    queue = deque()
    queue.append(start)
    log = set()
    log.add(start)

    while queue:
        vertex = queue.popleft()
        nodes = graph[vertex]
        for v in nodes:
            if v not in log:
                queue.append(v)
                log.add(v)

    return len(log)


def close_down(graph, node):
    del graph[node]
    for v in graph.values():
        if node in v:
            v.remove(node)

###############################################################################
# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')
sys.stdin = open('closing.in', 'r')
sys.stdout = open('closing.out', 'w')

N, M = map(int, sys.stdin.readline().split())

paths = defaultdict(set)
for i in range(M):
    barn1, barn2 = map(int, sys.stdin.readline().split())
    paths[barn1].add(barn2)
    paths[barn2].add(barn1)

last_data = sys.stdin.read().strip().split('\n')
last_barn = int(last_data[-1])
for j in range(N):
    if bfs_search(last_barn, paths) == N-j:
        print('YES')
    else:
        print('NO')

    close_down(paths, int(last_data[j]))