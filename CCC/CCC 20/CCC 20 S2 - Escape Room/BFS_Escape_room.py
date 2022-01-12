from collections import deque, defaultdict
from sys import stdin

stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

def bfs_search(start, end):
    if start == end:
        return True

    queue = deque()
    queue.append(start)
    log = set()

    while queue:
        x, y = queue.popleft()
        if room[x-1][y-1] not in log:
            nodes = number_p[room[x-1][y-1]]
            log.add(room[x - 1][y - 1])
            if end in nodes:
                return True
            for v in nodes:
                queue.append(v)

    return False


all_data = [[int(i) for i in j.split()] for j in stdin.read().split('\n')]

r, c = all_data[0][0], all_data[1][0]

room = []
for i in range(2, r+2):
    x = all_data[i]
    room.append(x)

number_p = defaultdict(list)
for row in range(1, r+1):
    for column in range(1, c+1):
        number_p[column*row].append((row, column))


if bfs_search((1, 1), (r, c)):
    print('yes')
else:
    print('no')