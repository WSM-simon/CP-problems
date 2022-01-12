import sys

m = int(sys.stdin.readline())
n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

choices = {}
for i in range(k):
    choice = sys.stdin.readline()
    if choice not in choices:
        choices[choice] = 1
    else:
        del choices[choice]

r = 0
c = 0
for item in choices.keys():
    if item[0] == "R":
        r += 1
    elif item[0] == "C":
        c += 1


result = r*n + c*m - 2*r*c

print(result)