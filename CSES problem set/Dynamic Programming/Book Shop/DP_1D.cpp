#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;
const int Max2 = 1e5 + 3;

int N, M, costs[Max], books[Max], dp[Max2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> costs[i];
    for (int i = 1; i <= N; ++i)
        cin >> books[i];
    for (int i = 1; i <= N; ++i)
        for (int j = M; j >= costs[i]; --j)
            dp[j] = max(dp[j], dp[j - costs[i]] + books[i]);

    cout << dp[M];
    return 0;
}