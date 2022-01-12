fin = open('guess.in', 'r')
fout = open('guess.out', 'w')

data = fin.read().split('\n')
n = int(data[0])

tuple_data = tuple(set() for i in range(n))

for i in range(n):
    l = data[i+1].split()
    for ii in range(int(l[1])):
        tuple_data[i].add(l[ii+2])

turn = 1
n_of_same_item_list = []
for v1 in tuple_data:
    for v2 in tuple_data[turn:]:
        n_of_same_item_list.append(len(v1&v2))
    turn += 1

max_same_item = max(n_of_same_item_list)

fout.write(str(max_same_item+1))

fin.close()
fout.close()




