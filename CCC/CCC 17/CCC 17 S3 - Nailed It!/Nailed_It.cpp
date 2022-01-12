#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define Max 2001
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;
int woods[Max], sums[2 * Max];

int main()
{
    scan(N);
    for (int i = 0; i < N; i++)
    {
        int tem;
        scan(tem);
        woods[tem]++;
    }

    for (int i = 1; i < 2001; i++)
        for (int j = i; j < 2001; j++)
        {
            if (i == j)
                sums[i + j] += woods[i] >> 1;
            else
                sums[i + j] += min(woods[i], woods[j]);
        }

    int best = 0, cnt = 0;
    for (int i : sums)
    {
        if (i > best)
        {
            best = i;
            cnt = 1;
        }
        else if (i == best)
            cnt++;
    }

    printf("%d %d", best, cnt);
    return 0;
}