#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 6e3;
int N, dp[Max];
vector<int> moves;
unordered_set<int> dpset[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int d;
    memset(dp, 0x3f, sizeof(dp));
    while (cin >> d)
    {
        moves.push_back(d);
        dp[d] = 1;
        dpset[d].insert(d);
    }
    for (int i = 1; i <= N; ++i)
        for (int d : moves)
            if (i >= d && dpset[i].find(d) == dpset[i].end())
            {
                dp[i]=min(dp[i], dp[i-d]+1);
                for (int d2:dpset[i-d])
                    dpset[i].insert(d2);
            }
    
    cout << dp[N];
    return 0;
}