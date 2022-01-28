#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 30;
const int inf = 0x3f3f3f3f;

int N, arr[Max], dp[Max][Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= N - 3; ++i)
    {
        int cnt = count(arr + i, arr + i + 4, 0);
        if (cnt > 0)
        {
            dp[i][i + 3] = cnt;
            if (cnt == 4)
                dp[i][i + 3] = inf;
        }
        else
            dp[i][i + 3] = 0;
    }

    for (int k = 4; k < N; ++k)
        for (int i = 1; i <= N - k; ++i)
            dp[i][i + k] = min(dp[i][i + k - 1], dp[i + 1][i + k]);
    cout << dp[1][N];
    return 0;
}
