import sys
from collections import deque, defaultdict
from math import pow

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

sys.stdin = open('moocast.in', 'r')
sys.stdout = open('moocast.out', 'w')


def plot(p1, p_l):
    x1, y1, p1 = p1
    tem_l = []
    for node in p_l:
        x2, y2, p2 = node
        if pow(x1-x2, 2) + pow(y1-y2, 2) <= pow(p1, 2):
            tem_l.append((x2, y2))
    return tem_l


def dfs_search(start, graph):
    queue = deque()
    queue.append(start)
    log = set()
    log.add(start)

    while queue:
        vertex = queue.popleft()
        nodes = path[vertex]

        for v in nodes & graph.keys():
            if v not in log:
                queue.append(v)
                log.add(v)

    return len(log)


data = [tuple(int(i) for i in j.split()) for j in sys.stdin.read().strip().split('\n')]
n = data[0][0]
path = defaultdict(set)
result_l = []
for i in data[1:]:
    path[(i[0], i[1])].update(plot(i, data[1:]))

for j in data[1:]:
    result_l.append(dfs_search((j[0], j[1]), path))

print(max(result_l))

