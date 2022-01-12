import sys
#
# sys.stdin = open("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r")
sys.stdin = open("mowing.in", "r")
sys.stdout = open("mowing.out", "w")

input = sys.stdin.readline

def search(node, cut, spe, cnt, direc, mag):
    x, y = node
    for _ in range(mag):
        cnt += 1
        if direc == 'N':
            x += 1
        elif direc == 'S':
            x -= 1
        elif direc == 'E':
            y -= 1
        elif direc == 'W':
            y += 1

        node = (x, y)
        if node in cut:
            spe.append(cnt - cut[node])

        cut[node] = cnt

    return cnt, node


if __name__ == "__main__":
    n = int(input())
    cut = {}
    speed = []

    node = (0, 0)
    cnt = 0
    for i in range(n):
        d, m = input().strip().split()
        m = int(m)
        cnt, node = search(node, cut, speed, cnt, d, m)

    if speed:
        print(min(speed))
    else:
        print(-1)
