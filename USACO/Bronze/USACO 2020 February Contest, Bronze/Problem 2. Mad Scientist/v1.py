fin = open('breedflip.in', 'r')
fout = open('breedflip.out', 'w')

data = fin.read().strip().split('\n')
cows_n = int(data[0])
line_A = data[1]
line_B = data[2]

n = 0
counter = 0
while n <= cows_n-1:
    if line_A[n] == line_B[n]:
        n += 1
    else:
        counter += 1
        n += 1
        while line_A[n] != line_B[n] and n <= cows_n-1:
            n += 1

fout.write(str(counter))

fin.close()

