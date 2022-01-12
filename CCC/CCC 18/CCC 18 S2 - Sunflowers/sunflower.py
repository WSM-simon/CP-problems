import sys
input = sys.stdin.readline


def is_sorted(l):
    for i in range(len(l) - 1):
        if l[i + 1] < l[i]:
            return False
    return True

def wrapper(row, col):
    def print1(i, j):
        print(grid[i][j], end=' ')
    def print2(i, j):
        print(grid[N-j-1][i], end=' ')
    def print3(i, j):
        print(grid[j][N-i-1], end=' ')
    def print4(i, j):
        print(grid[N-i-1][N-j-1], end=' ')

    if row and col:
        return print1
    elif row:
        return print2
    elif col:
        return print3
    else:
        return print4

N = int(input())
grid = []
for i in range(N):
    grid.append(list(map(int, input().split())))

fir_col = [grid[i][0] for i in range(N)]

row = is_sorted(grid[0])
col = is_sorted(fir_col)

my_print = wrapper(row, col)

for i in range(N):
    for j in range(N):
        my_print(i, j)
    print()
