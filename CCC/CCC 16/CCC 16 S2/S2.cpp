#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N, M;
vector<int> v1, v2;

void solve2()
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v1.begin(), v1.end());

    int ans = 0;
    for (int i = 0; i < M; ++i)
        ans += max(v1[i], v2[i]);
    cout << ans;
}
void solve1()
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = 0;
    for (int i = 0; i < M; ++i)
        ans += max(v1[i], v2[i]);
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int tem;
        cin >> tem;
        v1.push_back(tem);
    }
    for (int i = 0; i < M; ++i)
    {
        int tem;
        cin >> tem;
        v2.push_back(tem);
    }
    if (N == 1)
        solve1();
    if (N == 2)
        solve2();
    return 0;
}