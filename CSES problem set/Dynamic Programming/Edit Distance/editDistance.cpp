#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 5003;
const int MxM = 5003;

int N, M, dp[MxN][MxM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    N = (int)s1.size(), M = (int)s2.size();

    for (int i = 0; i <= N; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= M; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1)});

    cout << dp[N][M] << '\n';
    return 0;
}
