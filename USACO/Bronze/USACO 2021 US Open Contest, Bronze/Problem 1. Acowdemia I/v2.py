from sys import stdin

paper_n, add = map(int, stdin.readline().split())
papers = list(map(int, stdin.readline().split()))

papers_all = sorted(list(set(papers)))
h_dict = {papers_all[-1]: papers.count(papers_all[-1])}

for i in range(len(papers_all)-2, -1, -1):
    h_dict[papers_all[i]] = h_dict[papers_all[i+1]] + papers.count(papers_all[i])

for i in papers_all:
    if h_dict[i] < i:
        n = papers_all[papers_all.index(i)-1]
        break

next_n = lambda n: papers_all[papers_all.index(n)+1]
while True:
    try:
        if next_n(n) - h_dict[next_n(n)] <= add <= h_dict[n]:
            n = next_n(n)
        else:
            print(n)
            break
    except KeyError:
        print(n)
        break













