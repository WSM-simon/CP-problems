import sys
from copy import deepcopy

sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')
# sys.stdin = open("mooyomooyo.in", 'r')
# sys.stdout = open("mooyomooyo.out", 'w')


n, k = map(int, sys.stdin.readline().split())
mooyo_board = [list(j) for j in sys.stdin.read().strip().split('\n')]
default_components = set((r, c) for r in range(10) for c in range(n))


def dfs_search(node, components, graph):
    num = graph[node[1]][node[0]]
    if num == '0':
        return []

    stack = [node]
    log = set()
    log.add(node)

    while stack:
        x, y = stack.pop()
        adj_nodes = {(x + 1, y),
                     (x - 1, y),
                     (x, y + 1),
                     (x, y - 1)}

        for n in adj_nodes & components - log:
            if graph[n[1]][n[0]] == num:
                stack.append(n)
                log.add(n)
    return log


def refresh_pic(board, default_components):
    global k

    components_in = default_components.copy()
    while components_in:
        node = components_in.pop()
        cancels = dfs_search(node, components_in, board)
        if len(cancels) >= k:
            components_in -= cancels
            for a, b in cancels:
                board[b][a] = '0'


def fall_dwon(board):
    global n

    for c in range(10):
        for r in range(n - 1, -1, -1):
            for c in range(10):
                if board[r][c] != 0:
                    d = 1
                    try:
                        while board[r + d][c] == '0':
                            d += 1
                    except IndexError:
                        pass
                    if d != 1:
                        board[r + d - 1][c] = board[r][c]
                        board[r][c] = '0'


def print_m_b():
    global mooyo_board

    for line in mooyo_board:
        str_line = ''.join(line)
        print(str_line)


def solve():
    pre_graph = []
    while mooyo_board != pre_graph:
        pre_graph = deepcopy(mooyo_board)
        refresh_pic(mooyo_board, default_components)
        fall_dwon(mooyo_board)


if __name__ == '__main__':
    solve()
    print_m_b()
