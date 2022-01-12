import sys

alphabet = {'a':0, 'b':0, 'c':0, 'd':0, 'e':0, 'f':0, 'g':0, 'h':0,
     'i':0, 'j':0, 'k':0, 'l':0, 'm':0, 'n':0, 'o':0, 'p':0, 'q':0,
     'r':0, 's':0, 't':0, 'u':0, 'v':0, 'w':0, 'x':0, 'y':0, 'z':0,}

sys.stdin = open("blocks.in", "r")
N = int(sys.stdin.readline())

for i in range(N):
    tem_l = input().replace(' ', '')
    s = set(tem_l)
    for v in s:
        num_k1 = tem_l.count(v)
        num_k2 = tem_l.count(v)
        max_num_k = max(num_k1, num_k2)
        alphabet[v] += max_num_k

sys.stdout = open("blocks.out", 'w')
for v in alphabet.values():
    print(v)

