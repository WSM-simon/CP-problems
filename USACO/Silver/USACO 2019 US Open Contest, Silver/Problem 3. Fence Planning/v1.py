import sys
from collections import deque, defaultdict

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

sys.stdin = open('fenceplan.in', 'r')
sys.stdout = open('fenceplan.out', 'w')


def bfs_search(start, graph, memo):
    queue = deque()
    queue.append(start)
    log = set()
    log.add(start)
    x_value = {start[0]}
    y_value = {start[1]}

    while queue:
        value = queue.popleft()
        if value in memo:
            x_value.update(memo[value][0])
            y_value.update(memo[value][1])
            break
        nodes = graph[value]
        for v in nodes:
            if v not in log:
                queue.append(v)
                log.add(v)
                x_value.add(v[0])
                y_value.add(v[1])

    memo[start].append((max(x_value), min(x_value)))
    memo[start].append((max(y_value), min(y_value)))
    return max(x_value), min(x_value), max(y_value), min(y_value)


data = [tuple(int(i) for i in j.split()) for j in sys.stdin.read().strip().split('\n')]
N, M = data[0]

path = defaultdict(list) #set
for i in data[N+1:]:
    path[data[i[0]]].append(data[i[1]])
    path[data[i[1]]].append(data[i[0]])

area = []
memo = defaultdict(list)
for k in data[1:N+1]:
    max_x, min_x, max_y, min_y = bfs_search(k, path, memo)
    area.append(2 * (max_x-min_x) + 2 * (max_y - min_y))

print(min(area))


