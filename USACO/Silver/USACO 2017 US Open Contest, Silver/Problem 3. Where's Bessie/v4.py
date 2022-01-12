import sys
from collections import namedtuple, Counter
from time import time


sys.stdin = open(r'text_data/8.in', 'r')
# sys.stdin = open('where.in', 'r')
# sys.stdout = open('where.out', 'w')

Rect = namedtuple('R', ['i1', 'j1', 'i2', 'j2'])


def r_size(R): return (R.i2 - R.i1 + 1) * (R.j2 - R.j1 + 1)


# cost_is_in_pcl = 0
def is_in_pcl(R, R_pcl):
    # global cost_is_in_pcl
    # t1 = time()
    flag = R_pcl.i1 <= R.i1 <= R_pcl.i2 \
           and R_pcl.j1 <= R.j1 <= R_pcl.j2 \
           and R_pcl.i1 <= R.i2 <= R_pcl.i2 \
           and R_pcl.j1 <= R.j2 <= R_pcl.j2
    # t2 = time()
    # cost_is_in_pcl += t2 - t1
    return flag


# cost_r_colors = 0
def r_colors(R, pic):
    # global cost_r_colors
    # t1 = time()
    graph = ''
    for g in pic[R.i1:R.i2 + 1]:
        graph += g[R.j1:R.j2 + 1]

    # rect_colors = set(graph)
    # t2 = time()
    # cost_r_colors += t2 - t1
    return set(graph)


def graph_rect(R):
    return set((a, b) for a in range(R.i1, R.i2 + 1) for b in range(R.j1, R.j2 + 1))

# def draw_rect(R, pic):

# cost_dfs = 0
def dfs(start, graph, rect):
    # global cost_dfs
    # t1= time()
    stack = []
    stack.append(start)
    visited = set()
    visited.add(start)
    color = graph[start[0]][start[1]]

    while stack:
        x, y = stack.pop()
        adj_node = ((x + 1, y),
                    (x - 1, y),
                    (x, y + 1),
                    (x, y - 1))

        for v in adj_node:
            if v not in visited:
                if v in rect:
                    if graph[v[0]][v[1]] == color:
                        stack.append(v)
                        visited.add(v)

    # t2 = time()
    # cost_dfs += t2 - t1
    return visited, color


data = sys.stdin.read().strip().split('\n')
n = int(data[0])
pic = data[1:]

rect_list = [Rect(a, b, c, d)
             for a in range(n)
             for b in range(n)
             for c in range(a, n)
             for d in range(b, n)]

rect_list.sort(key=r_size, reverse=True)  # 把长方形从大到小排列


# t1 = time()
if __name__ == '__main__':
    log = []
    for R in rect_list:
        if r_size(R) < 3:
            continue

        if R.i1 - R.i2 == 1 and R.j1 - R.j2 == 1:
            continue

        if not any(is_in_pcl(R, pcl) for pcl in log):
            rect_co = r_colors(R, pic)
            if len(rect_co) == 2:    # 排除颜色不为两个的 rectangle
                go = True
                rect = graph_rect(R)
                c_a, c_b = rect_co
                co_counter = Counter()
                while rect and go:
                    start = rect.pop()
                    cencels, color = dfs(start, pic, rect)
                    co_counter[color] += 1
                    rect -= cencels

                    if len(co_counter) == 2 and any(co > 1 for co in co_counter.values()):  # 两值都大于1， 提前跳出
                        co_1 = ''
                        for key, value in co_counter.items():
                            if value == 1:
                                co_1 = key
                                break

                        for p1, p2 in rect:
                            if pic[p1][p2] == co_1:
                                go = False
                                break

                        if go:
                            log.append(R)
                            go = False
                            break


    # t2 = time()
    # print(t2 - t1)
    print(len(log))

    # print(cost_r_colors)
    # print(cost_is_in_pcl)
    # print(cost_dfs)

