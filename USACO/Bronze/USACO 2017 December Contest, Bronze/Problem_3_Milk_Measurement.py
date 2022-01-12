fin = open('measurement.in', 'r')
fout = open('measurement.out', 'w')

all_data = fin.read().split('\n')
n = int(all_data[0])
data_l = []
cows_produces  = {'Bessie':7, 'Elsie':7, 'Mildred':7}

for i in range(n):
    tem_l = all_data[i+1].split()
    data_l.append((int(tem_l[0]), tem_l[1], int(tem_l[2])))

data_l.sort(key=lambda l:l[0])

counter = 0
best_produces = 7

for i in data_l:
    if i[2]>0:
        cows_produces[i[1]] += i[2]
        best_produces = max(cows_produces.values())
        if cows_produces[i[1]] == best_produces:
            counter += 1

    else:
        if cows_produces[i[1]] < best_produces:
            cows_produces[i[1]] += i[2]
            continue

        else:
            cows_produces[i[1]] += i[2]
            best_produces = max(cows_produces.values())
            best_num = list(cows_produces.values()).count(best_produces)
            if cows_produces[i[1]] == best_produces:
                if best_num == 1:
                    continue
                else:
                    counter += 1




fout.write(str(counter))

fin.close()
fout.close()
