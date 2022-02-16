#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 253;
const int inf = 0x3f3f3f3f;

int N, K, dp[Max][Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    if (N == K)
    {
        cout << "1\n";
        return 0;
    }
    for (int i = 1; i <= N; ++i)
        dp[1][i] = 1;
    for (int i = 1; i <= K; ++i)
        dp[i][i] = 1;
    for (int i = 2; i <= K; ++i)
        for (int j = i + 1; j <= N; ++j)
        {
            int sub = 1;
            while (sub < j)
            {
                dp[i][j] += dp[i - 1][j - sub];
                sub += i;
            }
        }
    cout << dp[K][N] << '\n';
    return 0;
}
