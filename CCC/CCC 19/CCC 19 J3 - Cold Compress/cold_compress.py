import sys

sys.stdin = open(r'C:\Users\Simian\OneDrive\CCC_senior_2021_2\test\test.in', 'r')
data = sys.stdin.read().strip().split("\n")

N = int(data[0])
cnt = 0

for line in data[1:]:
    word = line[0]
    store = []
    for i in range(len(line)+1):
        if i == len(line):
            store.append(cnt)
            store.append(line[i-1])
            cnt = 0
            break

        if line[i] == word:
            cnt += 1
        else:
            store.append(cnt)
            store.append(word)
            word = line[i]
            cnt = 1

    for i in store:
        print(i, end=" ")
    print()








