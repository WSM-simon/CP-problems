#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e2 + 3;
const int MOD = 1e9 + 7;

int N, M, arr[MxN];
ll dp[MxN][MxM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    if (arr[0] == 0)
    {
        for (int i = 1; i <= M; ++i)
            dp[0][i] = 1;
    }
    else
        dp[0][arr[0]] = 1;
    for (int i = 1; i < N; ++i)
    {
        if (arr[i] == 0)
        {
            for (int j = 1; j <= M; ++j)
            {
                dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            }
        }
        else
        {
            dp[i][arr[i]] = (dp[i - 1][arr[i] + 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] - 1]) % MOD;
        }
    }

    int sum = 0;
    for (int j = 1; j <= M; ++j)
        sum = (sum + dp[N - 1][j]) % MOD;
    cout << sum << '\n';
    return 0;
}
