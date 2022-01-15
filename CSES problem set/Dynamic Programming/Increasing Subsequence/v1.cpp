#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;

int N, arr[Max], dp[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] > dp[cnt])
            dp[++cnt] = arr[i];
        else
            *lower_bound(dp, dp + cnt, arr[i]) = arr[i];
    }

    cout << cnt << '\n';
    return 0;
}