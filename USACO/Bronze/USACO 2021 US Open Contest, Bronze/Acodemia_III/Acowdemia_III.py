from sys import stdin
from itertools import combinations

def dispose(friends, friends_l, cow_n):
    if cow_n < 2:
        return False

    if cow_n == 2 and friends_l not in friends:
        friends.append(friends_l)
        return True

    else:
        for i in combinations(friends_l, 2):
            l = []
            l.append(i[0])
            l.append(i[1])

            if l not in friends:
                friends.append(l)
                return True


all_data = stdin.read().split('\n')
line1 = all_data[0].split()

rows = int(line1[0])
columns = int(line1[1])

pasture = [list(i) for i in all_data[1:]]
friends = []
ans = 0
for i in range(rows):
    for ii in range(columns):
        if pasture[i][ii] == 'G':
            cow_n = 0
            friends_l = []
            if i != 0:
                if pasture[i-1][ii] == 'C':
                    cow_n += 1
                    friends_l.append((i - 1,ii))
            if i != rows-1:
                if pasture[i+1][ii] == 'C':
                    cow_n += 1
                    friends_l.append((i + 1, ii))
            if ii != 0:
                if pasture[i][ii-1] == 'C':
                    cow_n += 1
                    friends_l.append((i, ii - 1))
            if ii != columns-1:
                if pasture[i][ii+1] == 'C':
                    cow_n += 1
                    friends_l.append((i, ii + 1))

            friends_l.sort()
            pasture[i][ii] = '.'
            if dispose(friends, friends_l, cow_n):
                ans += 1

print(ans)