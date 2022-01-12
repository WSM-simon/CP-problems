import sys
from collections import Counter, defaultdict

sys.stdin = open(r'text_data/8.in', 'r')


# sys.stdin = open('where.in', 'r')
# sys.stdout = open('where.out', 'w')

def r_size(R): return (R[2] - R[0] + 1) * (R[3] - R[1] + 1)


def is_in_pcl(R, R_pcl):
    flag = R_pcl[0] <= R[0] <= R_pcl[2] \
           and R_pcl[1] <= R[1] <= R_pcl[3] \
           and R_pcl[0] <= R[2] <= R_pcl[2] \
           and R_pcl[1] <= R[3] <= R_pcl[3]

    return flag


def r_colors(R, pic):
    graph = ''
    for g in pic[R[0]:R[2] + 1]:
        graph += g[R[1]:R[3] + 1]

    rect_colors = frozenset(graph)

    return rect_colors


def draw_rect(R):
    rect = set((a, b) for a in range(R[0], R[2] + 1) for b in range(R[1], R[3] + 1))
    return rect


def dfs(start, pic, rect, graph):
    stack = []
    stack.append(start)
    visited = set()
    visited.add(start)
    color = pic[start[0]][start[1]]

    while stack:
        node = stack.pop()
        adj_node = graph[node]

        for v in adj_node:
            if v not in visited:
                if v in rect:
                    if pic[v[0]][v[1]] == color:
                        stack.append(v)
                        visited.add(v)

    return visited, color


#######################################################################################################
data = sys.stdin.read().strip().split('\n')
n = int(data[0])
pic = data[1:]

rect_list = []
graph = defaultdict(list)
for i1 in range(n):
    for j1 in range(n):
        for (ni, nj) in ((i1 + 1, j1), (i1 - 1, j1), (i1, j1 + 1), (i1, j1 - 1)):
            if 0 <= ni < n and 0 <= nj < n:
                graph[(i1, j1)].append((ni, nj))

        for i2 in range(i1, n):
            for j2 in range(j1, n):
                rect_list.append((i1, j1, i2, j2))

rect_list.sort(key=r_size, reverse=True)  # 把长方形从大到小排列

if __name__ == '__main__':
    log = []
    for R in rect_list:
        if r_size(R) < 3:
            continue

        if R[0] - R[2] == 1 and R[2] - R[3] == 1:
            continue

        if not any(is_in_pcl(R, pcl) for pcl in log):
            rect_co = r_colors(R, pic)
            if len(rect_co) == 2:  # 排除颜色不为两个的 rectangle
                rect = draw_rect(R)
                c_a, c_b = rect_co
                co_counter = Counter()
                while rect:
                    start = rect.pop()
                    cencels, color = dfs(start, pic, rect, graph)
                    co_counter[color] += 1
                    rect -= cencels

                    if len(co_counter) == 2 and all(co > 1 for co in co_counter.values()):  # 两值都大于1， 提前跳出
                        break

                c_r_a, c_r_b = co_counter.values()
                if (c_r_a > 1) ^ (c_r_b > 1):  # 一种颜色仅有一个component，另一种大于1
                    log.append(R)

    print(len(log))
