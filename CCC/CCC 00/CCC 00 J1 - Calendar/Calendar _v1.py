f_d ,num_of_days = map(int, input().split())

l = []

if f_d > 1:
    l.append('   ')
    for _ in range(f_d - 2):
        l.append('    ')

for i in range(1,num_of_days+1):
    if i >= 10:
        if (i+f_d-1)%7 == 1:
            l.append(f' {i}')
        else:
            l.append(f'  {i}')
    else:
        if (i+f_d-1)%7 == 1:
            l.append(f'  {i}')
        else:
            l.append(f'   {i}')


print('Sun Mon Tue Wed Thr Fri Sat')
for i in range(len(l)):
    print(l[i], end="")
    if (i+1)%7 == 0 and i != len(l)-1:
        print('\n', end="")

print()

