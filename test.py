import sys
input = sys.stdin.readline

s = set()
l = []
N = int(input().strip())
for i in range(N):
    tem = int(input().strip())
    l.append(tem)
    s.add(tem)

ans = 999999999
first = l[0]
last = l[-1]
for i in l[1:]:
    now = first
    itv = i - first 
    if itv > 100000:
        break
    while(now+itv <= last):
        now += itv
        if now+itv > last:
            ans = min(ans, now+itv)
        if now not in s:
            break

print(ans)
