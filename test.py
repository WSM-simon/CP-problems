<<<<<<< HEAD

for n in range(1, 101):
    print(str(n)+" ++++++++")
    x = 50**n+(50*n+1)**50
    cnt = 0
    for i in range(1, 100001):
        if x % i == 0:
            cnt += 1
            if (cnt >= 4):
                break
            print(i)
    print()
=======
import sys

datas = sys.stdin.readlines()

for data in datas:
    words = data.split()
    words = words[::-1]
    out = []
    for word in words:
        if not word.isnumeric():
            out.append(word[::-1])
            continue
        out.append(word)
    print(" ".join(out))


>>>>>>> 7f771af9ba3fa8cd220cd41d9c4dbeb980103a2d
