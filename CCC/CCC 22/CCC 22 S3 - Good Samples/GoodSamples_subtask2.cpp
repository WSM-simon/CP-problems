#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int MxN = 1e5 + 3;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int N, M, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    if (K < N || K > 2 * N - 1)
    {
        cout << "-1\n";
        return 0;
    }
    K -= N;
    int lst = 1;
    cout << "1 ";
    for (int i = 0; i < N - 1; ++i)
    {
        if (K-- > 0)
        {
            if (lst == 1)
            {
                cout << 2 << "\n "[i == N - 2 ? 0 : 1];
                lst = 2;
            }
            else
            {
                cout << 1 << "\n "[i == N - 2 ? 0 : 1];
                lst = 1;
            }
        }
        else
        {
            cout << lst << "\n "[i == N - 2 ? 0 : 1];
        }
    }
    return 0;
}
