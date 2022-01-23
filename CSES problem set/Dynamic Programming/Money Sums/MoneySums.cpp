#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e2 + 3;

int N, dp[Max], coins[Max];
set<int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> coins[i];

    for (int i = 0; i < N; ++i)
    {
        vector<int> add;
        add.push_back(coins[i]);
        for (int j : ans)
            add.push_back(coins[i] + j);
        for (int j : add)
            ans.insert(j);
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';

    return 0;
}