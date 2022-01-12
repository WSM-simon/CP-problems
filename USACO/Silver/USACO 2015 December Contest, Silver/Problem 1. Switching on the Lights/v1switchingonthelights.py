import sys
from collections import defaultdict

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

sys.stdin = open('lightson.in', 'r')
sys.stdout = open('lightson.out', 'w')

data = [[int(i) for i in j.split()] for j in sys.stdin.read().strip().split('\n')]
n, m = data[0]

switch = defaultdict(list)

for x, y, a, b in data[1:]:
    switch[(x, y)].append((a, b))

lighted = set()
lighted.add((1, 1))


def swich_on(start, graph):
    global lighted
    stack = [start]
    log = set()

    while stack:
        x, y = value = stack.pop()

        if (
            (x, y) in log   # already visited this square
            or (x, y) not in lighted  # wrong color
            or (x < 1 or x > n or y < 1 or y > n)  # if out of boundary
        ): continue

        log.add(value)
        rooms = graph[value]
        lighted.update(rooms)

        stack.append((x + 1, y))
        stack.append((x - 1, y))
        stack.append((x, y + 1))
        stack.append((x, y - 1))


lights = -1
while lights != len(lighted):
    lights = len(lighted)
    swich_on((1, 1), switch)

print(lights)




