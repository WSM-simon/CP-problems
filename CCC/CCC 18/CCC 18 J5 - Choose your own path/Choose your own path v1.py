import sys
from collections import defaultdict, deque

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

def bfs_search(start, ends, graph):
    queue = deque()
    queue.append((0, start))
    log = set()
    log.add(start)
    page_length = 0
    go = True

    while queue:
        vertex = queue.popleft()
        nodes = graph[vertex[1]]
        for v in nodes:
            if go and v in ends:
                page_length = (vertex[0] + 2)
                log.add(v)
                go = False

            elif v not in log:
                queue.append((vertex[0]+1, v))
                log.add(v)

    if len(log) == n:
        return f'Y\n{page_length}'
    else:
        return f'N\n{page_length}'



n = int(sys.stdin.readline())

path = defaultdict(list)
ending = set()

for i in range(1, n+1):
    tem_l = [int(node) for node in sys.stdin.readline().split()]
    if tem_l != [0]:
        for v in tem_l[1:]:
            path[i].append(v)
    else:
        ending.add(i)

print(bfs_search(1, ending, path))





