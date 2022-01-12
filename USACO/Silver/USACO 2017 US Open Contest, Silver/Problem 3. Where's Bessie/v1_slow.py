import sys
from collections import Counter

# from func_WSM import timefoo
# from time import time
#
sys.stdin = open(r'text_data/8.in', 'r')
# sys.stdin = open('where.in', 'r')
# sys.stdout = open('where.out', 'w')


def dfs(start, graph, component):
    stack = []
    stack.append(start)
    visited = set()
    visited.add(start)
    n_color = graph[start[0]][start[1]]

    while stack:
        x, y = stack.pop()
        adj_node = {(x + 1, y),
                    (x - 1, y),
                    (x, y + 1),
                    (x, y - 1)}

        for v in adj_node & component - visited:
            if graph[v[0]][v[1]] == n_color:
                stack.append(v)
                visited.add(v)

    return visited, n_color


data = sys.stdin.read().strip().split('\n')
n = int(data[0])
pic = data[1:]

'''
整理长方形
for a in range(n):
    for b in range(n):
        for c in range(a, n):
            for d in range(b, n):
                rect = tuple((x, y) for x in range(a, c+1) for y in range(b, d+1))
                rect_list.append(rect)
'''

rect_list = [set((x, y) for x in range(a, c + 1) for y in range(b, d + 1)) for a in range(n) for b in range(n) for c in
             range(a, n) for d in range(b, n)]
rect_list.sort(key=len, reverse=True)  # 把长方形从大到小排列

if __name__ == '__main__':
    # cost = 0
    log = []
    for rect in rect_list:
        # t1 = time()

        if len(rect) < 3:
            continue

        if not any(rect.issubset(pcl) for pcl in log):
            # t2 = time()
            co_counter = Counter()
            for x, y in rect:
                co_counter[pic[x][y]] += 1
            if len(co_counter) == 2:  # 排除颜色不为两个的 rectangle
                component = rect.copy()
                co_rect = []
                c_a, c_b = co_counter.keys()
                while component:
                    start = component.pop()
                    cancels, color = dfs(start, pic, component)
                    co_rect.append(color)
                    component -= cancels

                c_r_a = co_rect.count(c_a)
                c_r_b = co_rect.count(c_b)

                if (c_r_a > 1) ^ (c_r_b > 1):  # 一种颜色仅有一个component，另一种大于1
                    log.append(rect)
            # else:
            #     t2 = time()
            #
            # cost += t2 - t1

    print(len(log))
    # print(cost)
