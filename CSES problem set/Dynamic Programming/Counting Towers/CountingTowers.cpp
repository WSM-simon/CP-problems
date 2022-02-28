#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e2 + 3;
const int MxM = 1e6 + 3;
const int MOD = 1e9 + 7;

int N;
ll dp[MxM][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1][0] = 1, dp[1][1] = 1;
    for (int i = 2; i < MxM; ++i)
    {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
    }
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        cout << (dp[t][0] + dp[t][1]) % MOD << '\n';
    }
    return 0;
}
