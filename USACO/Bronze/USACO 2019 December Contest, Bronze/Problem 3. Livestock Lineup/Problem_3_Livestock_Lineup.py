import sys
from collections import defaultdict
from itertools import permutations

sys.stdin = open('lineup.in', 'r')
# sys.stdout = open('lineup.out', 'w')

def ifconform(tup):
    for k, v in order.items():
        k_ind = tup.index(k)
        if k_ind == 0:
            for i in v:
                if i == tup[1]:
                    continue
                else:
                    return False
        elif k_ind == 7:
            for i in v:
                if i == tup[6]:
                    continue
                else:
                    return False

        else:
            for i in v:
                if i == tup[k_ind - 1] or i == tup[k_ind + 1]:
                    continue
                else:
                    return False

        return True


name = ['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue']
perm = permutations(name)
order = defaultdict(list)

n = int(input())
for i in range(n):
    temp = input().split()
    order[temp[0]].append(temp[-1])

for p in perm:
    if ifconform(p):
        for i in p:
            print(i)
        print()
