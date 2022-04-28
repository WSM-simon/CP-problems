input = sys.stdin.readline


def calculate(m, s, d, n):
    out = [s]
    d[s] -= 1
    visited = set()
    if d[s] == 0:
        visited.add(s)

    sorting = list(d.keys())
    sorting.sort()
    while len(out) != n:
        minv = sys.maxsize

        for i in sorting:
            if i in visited:
                continue
            if i + out[-1] >= m:
                if i < minv:
                    minv = i

        if minv == sys.maxsize:
            return False
        else:
            d[minv] -= 1
            if d[minv] == 0:
                visited.add(minv)
            out.append(minv)
    return out


n, m = [int(x) for x in input().split()]
d = defaultdict(lambda: None)
for i in input().split():
    i = int(i)
    if i in d:
        d[i] += 1
    else:
        d[i] = 1

s = min(list(d.keys()))
ret = calculate(m, s, d, n)
if ret:
    print(*ret, sep=" ")
else:
    print(-1)
