import sys
from collections import deque

sys.stdin = open('pails.in', 'r')
sys.stdout = open('pails.out', 'w')

# sys.stdin = open('pails_silver_feb16/8.in', 'r')
X, Y, K, M = map(int, sys.stdin.read().strip().split())


def search(start, X, Y, K):
    queue = deque()
    queue.append((start, 0))
    visited = set()
    visited.add(start)

    while queue:
        value, counter = queue.popleft()
        if counter == K:
            break

        a, b = value
        next_node = {(X, b), (a, Y), (a, 0), (0, b)}  # empty and fill each pail

        # try to fill b with a
        a_to_b = a + b - Y
        if a_to_b > 0:
            next_node.add((a_to_b, Y))
        elif a_to_b == 0:
            next_node.add((0, Y))
        elif a_to_b < 0:
            next_node.add((0, b + a))

        # try to fill a with b
        b_to_a = b + a - X
        if b_to_a > 0:
            next_node.add((X, b_to_a))
        elif b_to_a == 0:
            next_node.add((X, 0))
        elif b_to_a < 0:
            next_node.add((a + b, 0))

        for value in next_node - visited:
            queue.append((value, counter + 1))
            visited.add(value)

    return visited


log = search((0, 0), X, Y, K)
print(sorted([abs(a + b - M) for a, b in log])[0])
