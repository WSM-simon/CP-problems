#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 25003;

int N, M, ans[Max + 2];
bool vis[Max + 2][Max + 2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ofstream fout;
    fout.open("a.out");

    ans[1] = 5;
    vis[0][1] = 1;
    vis[1][0] = 1;
    vis[0][0] = 1;
    for (ll r = 2; r <= Max; ++r)
    {
        cout << r << '\n';
        int add = 0;
        for (ll x = 0; x <= r; ++x)
            for (ll y = 0; y <= r; ++y)
            {
                if (vis[x][y] == 1)
                    continue;
                if (x * x + y * y <= r * r)
                {
                    add++;
                    vis[x][y] = 1;
                }
                else
                    break;
            }
        ans[r] += ans[r - 1] + add * 4 - 4;
    }
    for (int i = 1; i <= Max; ++i)
        fout << ans[i] << ' ';
    return 0;
}
