from sys import stdin

all_data = stdin.read().split('\n')
line1 = all_data[0].split()
line2 = all_data[1].split()

paper_n = int(line1[0])
add = int(line1[1])

paper_1 = list(map(int, line2))
paper_2 = [[i,0] for i in paper_1]

test_h = min(paper_1)
del paper_1

ans = 0
while True:
    counter = 0
    remove_l = []
    for i in paper_2:
        if i[0] >= test_h:
            counter += 1
        elif i[0] < test_h-1:
                remove_l.append(i)

    if len(remove_l) > 0:
        for i in remove_l:
            paper_2.remove(i)

    if counter >= test_h:
        ans += 1
        test_h += 1
    else:
        addee_n = 0
        for i in paper_2:
            if i[0] == test_h - 1 and i[1] == 0:
                addee_n += 1

        if add >= addee_n >= test_h-counter:
            for _ in range(test_h-counter):
                paper_2[paper_2.index([test_h-1,0])][0] += 1
                paper_2[paper_2.index([test_h,0])][1] = 1
            add -= test_h-counter
        else:
            break

print(ans)




