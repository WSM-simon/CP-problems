import sys
from sys import stdin

N = int(stdin.readline().strip())
data = list(map(int, stdin.readline().strip().split()))

data.sort()

# this dictionary tells me how many cows can afford a maxmium of i dollars
dic = dict()
for i in data:
    if i in dic:
        dic[i] += 1
    else:
        dic[i] = 1

# this set tells me how many kinds of cows are there
s = list(set(data))

mx_gain = 0
min_fee = 9999999
remain_cows = N
for fee in s:
    if ((fee * remain_cows) > mx_gain):
        mx_gain = fee * remain_cows
        for 

print(f"{mx_gain} {min_fee}")
