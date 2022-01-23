#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e2 + 3;
const int Max2 = 1e5 + 3;

int N, coins[Max];
bool dp[Max2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> coins[i];

    dp[0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = Max2; j >= coins[i]; --j)
            dp[j] |= dp[j - coins[i]];

    vector<int> possible;
    for (int i = 1; i <= Max2; ++i)
        if (dp[i])
            possible.push_back(i);

    cout << possible.size() << '\n';
    for (int i : possible)
        cout << i << ' ';

    return 0;
}