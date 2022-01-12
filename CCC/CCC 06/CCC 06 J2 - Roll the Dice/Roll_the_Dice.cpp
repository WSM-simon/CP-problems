M = int(input())
N = int(input())

if M > 9: M=9
if N > 9: N=9
    
cnt=0
log = set()

for i in range(1, M+1):
    if 10-i <= N:
        t = tuple(sorted([M, 10-i]))
  
        if t not in log:
            log.add(t)
            cnt += 1

if cnt == 1:
    print('There is 1 way to get the sum 10.')
else:
    print(f'There are {cnt} ways to get the sum 10.')