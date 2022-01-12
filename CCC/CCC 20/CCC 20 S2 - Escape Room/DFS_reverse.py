from collections import defaultdict
from sys import stdin

# stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')


def bfs_search(start, end, graph):
    if start == end:
        return True

    stack = list()
    stack.append(end)
    log_p = set()

    while stack:
        x, y = stack.pop()
        if x*y not in log_p:
            nodes = graph[x*y]
            log_p.add(x * y)
            if start in nodes:
                return True
            for v in nodes:
                stack.append(v)


    return False


all_data = [[int(i) for i in j.split()] for j in stdin.read().split('\n')]

r, c = all_data[0][0], all_data[1][0]

room = []
for i in range(2, r+2):
    x = all_data[i]
    room.append(x)

number_p = defaultdict(set)
for row in range(r):
    for column in range(c):
        number_p[room[row][column]].add((row+1, column+1))

if bfs_search((1, 1), (r, c), number_p):
    print('yes')
else:
    print('no')