import bisect
from sys import stdin

input = stdin.readline
N, M = (int(x) for x in input().split())
data_in = sorted([int(x) for x in input().split()])
odd = []
even = []
ans = []

for i in range(1,len(data_in)+1):
    if (i%2==0):
        even.append(data_in[i])
    else:
        odd.append(data_in[i])

even_ptr = 0
for i in range(len(odd)):
    ans.append(odd[i])
    while(odd[i] + even[even_ptr] < M):
        if even_prt>=len(even):
            if i == len(odd)-1:
                print(-1)
                exit()
            if odd[i] + odd[i+1] >= M:
            break
        even_ptr+=1
    

if len(ans) == N:
    print(*ans)

