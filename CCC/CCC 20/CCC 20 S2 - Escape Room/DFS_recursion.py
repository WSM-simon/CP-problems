from collections import defaultdict
from sys import stdin, setrecursionlimit

stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')
setrecursionlimit(10**5)

def dfs_search(node, end, graph, log):
    if node not in log:
        nodes = number_p[room[node[0]-1][node[1]-1]]
        log.add(node)
        if end in nodes:
            return True
        for v in nodes:
            if dfs_search(v, end, graph, log):
                return True


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

log = set()
if dfs_search((1, 1), (r, c), number_p, log):
    print('yes')
else:
    print('no')