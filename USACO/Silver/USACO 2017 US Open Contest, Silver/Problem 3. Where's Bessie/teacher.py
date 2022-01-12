import sys
from collections import Counter, defaultdict
from copy import deepcopy
# from time import time

sys.stdin = open('where.in', 'r')
sys.stdout = open('where.out', 'w')

# t1 = time()

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')

data = sys.stdin.read().split('\n')

N = int(data[0].strip())
image = []
for i in range(N):
    image.append(data[i+1].strip())


def icolor(pic):
    colors = ''
    for line in pic:
        colors += line
    return Counter(colors)


def connections(x, y):  # graph
    graph = defaultdict(set)
    for i in range(x[0], y[0]+1):
        for j in range(x[1], y[1]+1):
            for (ni, nj) in {(i+1, j), (i-1, j), (i, j+1), (i, j-1)}:
                if x[0] <= ni <= y[0] and x[1] <= nj <= y[1]:
                    graph[(i, j)].add((ni, nj))
    return graph


def connect_search(graph, p):  # search for components
    stack = []
    stack.append(p)
    visited = set()
    visited.add(p)
    c = image[p[0]][p[1]]

    while len(stack) > 0:
        vertex = stack.pop()
        nodes = graph[vertex]
        for v in nodes:
            if v not in visited and image[v[0]][v[1]] == c:
                stack.append(v)
                visited.add(v)

    return visited, c


pcl = set()
for i in range(N):
    for j in range(N):
        for k in range(N-1, -1, -1):
            for p in range(N-1, -1, -1):
                rect = [row[j:p+1] for row in image[i:k+1]]
                color_count = icolor(rect)
                if len(color_count) == 2:  # only two colors
                    g = connections((i, j), (k, p))
                    rect_pos = set(g.keys())
                    pos = tuple(rect_pos)

                    spotted = []  # find components
                    while len(rect_pos) > 0:
                        group = connect_search(g, rect_pos.pop())
                        spotted.append(group)
                        rect_pos = rect_pos - group[0]

                    if len(spotted) < 3:  # components is less than 3
                        continue
                    else:  # components is no less than 3
                        block_color = []  # count block color
                        for item in spotted:
                            block_color.append(item[1])
                        for num in Counter(block_color).values():
                            if num == 1:  # match the patterns
                                flag = True
                                for p in pcl:
                                    if set(pos) < set(p):
                                        flag = False
                                        break
                                if flag:
                                    pcl.add(pos)

print(len(pcl))


# t2 = time()
# print(t2-t1)