#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 30;
const int inf = 0x3f3f3f3f;

int K, arr[Max], dp[Max][Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    for (int i = 1; i <= K; ++i)
        cin >> arr[i];

    memset(dp, 0x3f, sizeof(dp));

    for (int i = 1; i <= K; ++i)
        dp[i][i + 3] = count(arr + i, arr + i + 3, 0);

    for (int i = 1; i <= K; ++i)
        for (int j = 1; j <= K; ++j)
            for (int k = i; k < j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);

    cout << dp[1][K];
    return 0;
}
