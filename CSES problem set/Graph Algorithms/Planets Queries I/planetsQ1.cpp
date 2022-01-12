#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;
const int MaxD = 30;

int N, M, e[Max][MaxD];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        cin >> e[i][0];

    for (int i = 1; i < MaxD; ++i)
        for (int j = 1; j <= N; ++j)
            e[j][i] = e[e[j][i - 1]][i - 1];

    while (M--)
    {
        int x, k;
        cin >> x >> k;
        bitset<MaxD> c(k);
        for (int i = 0; i < MaxD; ++i)
            if (c.test(i))
                x = e[x][i];
        cout << x << '\n';
    }
    return 0;
}