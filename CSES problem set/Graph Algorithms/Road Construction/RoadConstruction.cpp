#include <bits/stdc++.h>
#define ll long long
#define pii pair<int int>

using namespace std;

const int Max = 1e5 + 1;
int N, M, biggest = -1, com, e[Max];

int get(int t) { return e[t] < 0 ? t : get(e[t]); }

void unite(int x, int y)
{
    int ex = get(x), ey = get(y);
    if (ex == ey)
        return;
    if (e[ex] > e[ey])
        swap(ex, ey);
    e[ex] += e[ey], e[ey] = ex;
    biggest = min(biggest, e[ex]);
    --com;
}

int main()
{
    memset(e, -1, sizeof(e));
    scanf("%d %d\n", &N, &M);
    com = N;

    for (int i = 0; i < M; ++i)
    {
        int t1, t2;
        scanf("%d %d\n", &t1, &t2);
        unite(t1, t2);
        printf("%d %d\n", com, -biggest);
    }

    return 0;
}