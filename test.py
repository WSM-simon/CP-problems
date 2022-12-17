
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
