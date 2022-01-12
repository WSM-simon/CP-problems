from collections import deque
with open('socdist1.in', 'r') as fin:
    num_of_stalls = int(fin.readline())
    stalls = fin.readline().strip()

stalls = list(map(int, stalls))
left_0 = []
right_0 = []

while stalls[0] == 0:
    left_0.append(stalls[0])
    del stalls[0]
while stalls[-1] == 0:
    right_0.append(stalls.pop())



'''with open('socdist1.out', 'w') as fout:
    fout.write(answer)'''


