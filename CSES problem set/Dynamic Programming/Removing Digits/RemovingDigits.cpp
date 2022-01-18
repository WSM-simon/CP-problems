#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e6 + 3;

int N, dp[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    queue<int> q;
    q.push(N);

    memset(dp, 0x3f, sizeof(dp));
    dp[N] = 0;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        string s = to_string(n);

        int d = 0;
        for (char c : s)
            d = max(d, c-'0');
        if (dp[n - d] > dp[n] + 1)
        {
            q.push(n - d);
            dp[n - d] = dp[n] + 1;
        }
    }

    cout << dp[0];
    return 0;
}