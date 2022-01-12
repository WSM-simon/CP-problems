from sys import stdin
from itertools import combinations

def count_cows_beside(x, y):
    cow_n = 0
    if y != 0:
        if pasture[y - 1][x] == 'C':
            cow_n += 1
            friends_l.append((y - 1, x))
    if y != rows - 1:
        if pasture[y + 1][x] == 'C':
            cow_n += 1
            friends_l.append((y + 1, x))
    if x != 0:
        if pasture[i][ii - 1] == 'C':
            cow_n += 1
            friends_l.append((y, x - 1))
    if x != columns - 1:
        if pasture[i][ii + 1] == 'C':
            cow_n += 1
            friends_l.append((y, x + 1))


def dispose(friends, friends_l):
    cow_n = len(friends_l)
    if cow_n < 2:
        return False

    elif cow_n == 2:
        friends_l.sort()
        friends.add(tuple(friends_l))
        return True

    else:
        for i in combinations(friends_l, 2):
            friends_tup = (i[0], i[1])
            if friends_tup not in friends:
                friends.add(friends_tup)
                return True


all_data = stdin.read().split('\n')
line1 = all_data[0].split()

rows = int(line1[0])
columns = int(line1[1])

pasture = [list(i) for i in all_data[1:]]
friends = set()

for i in range(rows):
    for ii in range(columns):
        if pasture[i][ii] == 'G':
            friends_l = []
            count_cows_beside(ii, i)
            dispose(friends, friends_l)

print(len(friends))


