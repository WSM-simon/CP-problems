def solve_line(line):
    r = 0
    l = 0

    for i in range(len(line)-1):
        temp = line[i:i+2]
        if ((temp == "NE") or (temp == "ES") or (temp == "SW") or (temp =="WN")):
            r += 1
        elif ((temp == "EN") or (temp == "SE") or (temp == "WS") or (temp == "NW")):
            l += 1
    
    if r > l:
        return 'CW'
    else:
        return 'CCW'

            
if __name__ == "__main__":
    N = int(input().strip())
    ans_l = []

    for i in range(N):
        line = input().strip()
        ans = solve_line(line)
        ans_l.append(ans)
    
    for i in ans_l:
        print(i)