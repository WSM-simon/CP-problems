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
display_l_a = []
display_l_b = ['Bessie', 'Elsie', 'Mildred']
counter = 0

for i in data_l:
    cows_produces[i[1]] += i[2]
    for k, v in cows_produces.items():
        if v == max(cows_produces.values()):
            display_l_a.append(k)
    if display_l_a != display_l_b:
        counter += 1
    display_l_b = display_l_a
    display_l_a = []

fout.write(str(counter))

fin.close()
fout.close()
