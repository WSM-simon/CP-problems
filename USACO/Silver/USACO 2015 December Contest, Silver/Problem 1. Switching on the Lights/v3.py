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


def adj_rooms_tuple(node):
    x, y = node
    return (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)


def adj_rooms_set(node):
    x, y = node
    return {(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)}


def swich_on(start, graph):
    stack = [start]
    log = set()
    lighted = set()
    lighted.add((1, 1))
    component = set()
    component.add((1, 1))

    while stack:
        x, y = value = stack.pop()

        if (
            (x, y) in log  # already visited this square
            or (x, y) not in lighted  # wrong color
            or (x < 1 or x > n or y < 1 or y > n)  # if out of boundary
        ): continue

        component.add(value)
        log.add(value)

        will_light_rooms = graph[value]
        lighted.update(will_light_rooms)
        for j in will_light_rooms:
            if adj_rooms_set(j) & component:
                component.add(j)
                stack.append(j)

        stack.extend(adj_rooms_tuple(value))

    return len(lighted)


print(swich_on((1, 1), switch))
