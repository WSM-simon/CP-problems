import sys
from collections import defaultdict, deque
from time import time

# sys.stdin = open(r'data_in\4.in', 'r')
# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

sys.stdin = open('countcross.in', 'r')
sys.stdout = open('countcross.out', 'w')


data = [tuple(int(i) for i in j.split()) for j in sys.stdin.read().strip().split('\n')]

n, k, r = data[0]

fenses = defaultdict(list)
for x, y, a, b in data[1:r+1]:
    fenses[(x, y)].append((a, b))
    fenses[(a, b)].append((x, y))

cows_all = set(t for t in data[r+1:])

del data

non_distant = defaultdict(set)
def dfs_search(node, graph):
    stack = [node]
    log = set()
    log.add(node)
    cows = set()
    cows.add(node)

    while stack:
        x, y = value = stack.pop()

        next_step = [(x, y + 1),
                     (x, y - 1),
                     (x + 1, y),
                     (x - 1, y)]

        for v in next_step:
            r, c = v
            if ((1 <= c <= n and 1 <= r <= n) and
                v not in log and
                v not in graph[value]):

                if v in cows_all:
                    cows.add(v)

                stack.append(v)
                log.add(v)

    for cow in cows:
        non_distant[cow].update(cows)


while non_distant.keys() != cows_all:
    node = (cows_all-non_distant.keys()).pop()
    dfs_search(node, fenses)


ans = 0
for cow in cows_all:
    ans += len(cows_all - non_distant[cow])
 
print(int(ans/2))








