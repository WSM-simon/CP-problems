from collections import defaultdict, deque
from sys import stdin


def knght_move(k1, k2):
    move_set = set()
    for (ni, nj) in {(k1 + 1, k2 + 2), (k1 + 2, k2 + 1), (k1 + 2, k2 - 1), (k1 + 1, k2 - 2), (k1 - 1, k2 - 2), (k1 - 2, k2 - 1), (k1 - 2, k2 + 1), (k1 - 1, k2 + 2)}:
        if (0 < ni < 9) and (0 < nj < 9):
            move_set.add((ni, nj))
    return move_set

def BFS_search(start, end):
    queue = deque()
    queue.append((0, start))
    log = set()
    log.add(start)

    while queue:
        vertex = queue.popleft()
        nodes = knght_move(vertex[1][0], vertex[1][1])
        if end in nodes:
            steps = vertex[0] + 1
            break
        for v in nodes:
            if v not in log:
                queue.append((vertex[0]+1, v))
                log.add(v)

    return steps


s1, s2 = map(int, stdin.readline().split())
f1, f2 = map(int, stdin.readline().split())

chessboard = defaultdict(set)

if (s1,s2) == (f1,f2):
    print(0)
else:
    steps = BFS_search((s1,s2), (f1,f2))
    print(steps)


