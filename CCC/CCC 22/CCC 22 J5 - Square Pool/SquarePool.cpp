#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int MxN = 1e5 + 3;
const int MxT = 103;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int N, T, trees[MxT];

bool check(int a)
{
    int x1 = 1, y1 = 1, x2 = a, y2 = a;
    while (x2 <= N && y2 <= N)
    {
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    for (int i = 0; i < T; ++i)
        cin >> trees[i];
    int k = 0;
    for (int i = N >> 1; i >= 1; i >>= 1)
    {
        while (i + k <= N && check(i + k))
            k += i;
    }
    cout << k << '\n';

    return 0;
}
