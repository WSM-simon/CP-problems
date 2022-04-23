#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MxN = 1e3 + 3;

int N, is_river[MxN][MxN], height[MxN][MxN], ans1[MxN][MxN], ans2[MxN][MxN];
bool vis1[MxN][MxN];
queue<pii> q;

void solve1()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            char c;
            cin >> c;
            if (c == 'R')
            {
                is_river[i][j] = 1;
                q.push({i, j});
            }
        }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> height[i][j];

    return 0;
}
