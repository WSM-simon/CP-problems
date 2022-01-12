#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N;
ll apples[21];

ll solve(int t, ll s1, ll s2)
{
    if (t == N)
        return abs(s1 - s2);
    else
        return (min(solve(t + 1, s1 + apples[t], s2), solve(t + 1, s1, s2 + apples[t])));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> apples[i];
    }

    cout << solve(0, 0, 0);
    return 0;
}