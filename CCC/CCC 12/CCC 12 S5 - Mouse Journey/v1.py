import sys
all_data = sys.stdin.read().split('\n')
r, c = map(int, all_data[0].split())
cat_l = [tuple(map(int, all_data[i+2].split())) for i in range(int(all_data[1]))]
grid = [[0 for i in range(c)]for ii in range(r)]

for i in cat_l:
    grid[i[0]-1][i[1]-1] = float('inf')

for i in range(c):
    if grid[0][i] != float('inf'):
        grid[0][i] = 1
    else:
        break

for i in range(r):
    if grid[i][0] != float('inf'):
        grid[i][0] = 1
    else:
        break

for i in range(1,r):
    for ii in range(1,c):
        if grid[i][ii] != float('inf'):
            if grid[i-1][ii] != float('inf'):
                grid[i][ii] = grid[i-1][ii]
            if grid[i][ii-1] != float('inf'):
                grid[i][ii] += grid[i][ii-1]
        else:
            continue

print(grid[-1][-1])
