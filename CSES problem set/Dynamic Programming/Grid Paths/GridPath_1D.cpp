#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;
const int Mod = 1e9 + 7;

int N, dp[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    dp[1] = 1;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                dp[j] = 0;
                continue;
            }
            dp[j] = (dp[j] + dp[j - 1]) % Mod;
        }
    }

    cout << dp[N];

    return 0;
}