import sys


def time_add(t):
    t += 1
    if t % 100 >= 60:
        t -= 60
        t += 100

    if t >= 1300:
        t -= 1200
    return t


if __name__ == "__main__":
    t_add = int(sys.stdin.readline().strip())
    t = 1200
    fav = 0
    for i in range(t_add % 720):
        t = time_add(t)
        if t < 1000:
            hun, ten, dig = t // 100, (t % 100) // 10, (t % 10)
            if hun - ten == ten - dig:
                fav += 1

        else:
            thou, hun, ten, dig = t // 1000, (t % 1000) // 100, (t % 100) // 10, (t % 10)
            if thou - hun == hun - ten == ten - dig:
                fav += 1

    fav += (t_add//720) * 31
    print(fav)
