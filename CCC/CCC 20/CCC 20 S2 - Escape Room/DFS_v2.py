from collections import defaultdict
import sys
from array import array

sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

def dfs_search(start, end, graph):
    stack = array('b')
    stack.append(start)
    log = set()
    log.add(start)

    while stack:
        num = stack.pop()
        nodes = graph[num]
        if end in nodes:
            return True
        for v in nodes:
            if v not in log:
                stack.append(v)
                log.add(v)

    return False


all_data = sys.stdin.read().strip().split('\n')
r, c = int(all_data[0]), int(all_data[1])

nums = []
for i in range(2, r+2):
    nums.extend(int(x) for x in all_data[i].split())

rooms = [i*j for i in range(1, r+1) for j in range(1, c+1)]

path = defaultdict(list)
for i in range(r*c):
    path[rooms[i]].append(nums[i])


if dfs_search(1, r*c, path):
    print('yes')
else:
    print('no')



