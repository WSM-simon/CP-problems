from collections import defaultdict
from sys import stdin, setrecursionlimit
setrecursionlimit(10**5)
stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

def dfs_search(node, end, graph, log):
    if node not in log:
        nodes = graph[node]
        log.add(node)
        if end in nodes:
            return True
        for v in nodes:
            if dfs_search(v, end, graph, log):
                return True


all_data = stdin.read().strip().split('\n')
r, c = int(all_data[0]), int(all_data[1])

nums = []
for i in range(2, r+2):
    nums.extend(int(x) for x in all_data[i].split())

rooms = [i*j for i in range(1, r+1) for j in range(1, c+1)]

path = defaultdict(list)
for i in range(r*c):
    path[rooms[i]].append(nums[i])

log = set()
if dfs_search(1, r*c, path, log):
    print('yes')
else:
    print('no')



