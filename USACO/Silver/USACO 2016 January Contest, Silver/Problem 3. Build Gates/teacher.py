from collections import defaultdict
import sys

sys.stdin = open('gates.in', 'r')
sys.stdout = open('gates.out', 'w')

input = sys.stdin.readline

N = int(input().strip())

line = input().strip()

cnn = defaultdict(set)  # fences dict
pos = [(0, 0)]  # fences list
# fences = set()

for i in range(N):
    if i == 0:
        if line[i] == 'N':
            cnn[(0, 0)].add((0, 1))
            pos.append((0, 1))
        elif line[i] == 'S':
            cnn[(0, 0)].add((0, -1))
            pos.append((0, -1))
        elif line[i] == 'E':
            cnn[(0, 0)].add((1, 0))
            pos.append((1, 0))
        elif line[i] == 'W':
            cnn[(0, 0)].add((-1, 0))
            pos.append((-1, 0))
    else:
        if line[i] == 'N':
            cnn[pos[i]].add((pos[i][0], pos[i][1]+1))
            pos.append((pos[i][0], pos[i][1]+1))
        elif line[i] == 'S':
            cnn[pos[i]].add((pos[i][0], pos[i][1]-1))
            pos.append((pos[i][0], pos[i][1]-1))
        elif line[i] == 'E':
            cnn[pos[i]].add((pos[i][0]+1, pos[i][1]))
            pos.append((pos[i][0]+1, pos[i][1]))
        elif line[i] == 'W':
            cnn[pos[i]].add((pos[i][0]-1, pos[i][1]))
            pos.append((pos[i][0]-1, pos[i][1]))


def dfs(graph, p):
    stack = []
    stack.append(p)
    visited = set()
    visited.add(p)
    fences = set()
    cycle = 0

    while len(stack) > 0:
        vertex = stack.pop()
        nodes = graph[vertex]

        for v in nodes:
            fences.add((vertex, v))  # add fences
            if v not in visited:
                stack.append(v)
                visited.add(v)
            else:  # get rid of repeated fences
                if (v, vertex) not in fences:
                    cycle += 1

    return cycle


print(dfs(cnn, (0, 0)))