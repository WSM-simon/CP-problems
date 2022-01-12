with open('socdist1.in', 'r') as fin:
    num_of_stalls = fin.readline().strip()
    stalls = fin.readline().strip()

stalls_empty = stalls.split('1')
l = []
while '' in stalls_empty:
    del stalls_empty[stalls_empty.index('')]

for i in stalls_empty:
    l.append(list(i))

left_0 = []
right_0 = []

while stalls_empty[-1] == 0:
    left_0.append(stalls[0])
    print(stalls[0])
    del stalls[0]
while stalls_empty[0] == 0:
    left_0.append(stalls_empty.pop())

print(stalls_empty)
print(right_0)
print(left_0)