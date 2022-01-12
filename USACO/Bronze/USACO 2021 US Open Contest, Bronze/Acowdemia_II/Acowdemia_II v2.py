from sys import stdin

publications_n, names_n = map(int, stdin.readline().split())
names = stdin.readline().split()

seniority = {}
for name in names:
    seniority[name] = [set(), set()]

for i in range(publications_n):
    line = stdin.readline().split()
    for ii in range(names_n-1):
        if line[ii] > line[ii+1]:
            for name in line[:ii+1]:
                seniority[name][1].update(line[ii+1:])
            for name in line[ii+1:]:
                seniority[name][0].update(line[:ii+1])
    else:
        continue

print_l = ['?' for i in range(names_n)]
for i in range(names_n):
    print_lc = print_l.copy()
    print_lc[i] = 'B'
    for j in range(names_n):
        if names[j] in seniority[names[i]][0]:
            print_lc[j] = 1
        elif names[j] in seniority[names[i]][1]:
            print_lc[j] = 0
        else:
            continue
    print("".join(str(x) for x in print_lc))

