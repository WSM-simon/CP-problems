#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
const int inf = 0x3f3f3f3f;

int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    int cnt = 0;
    vector<int> v;
    string s;
    cin >> s;
    for (int i = 0; i < N; ++i)
    {
        int tem = s[i] - '0';
        if (tem == 0)
            cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 0;
        }
        if (i == N-1)
        {
            v.push_back(cnt);
            cnt = 0;
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < (K > v.size() ? v.size() : K); ++i)
        ans += v[i];
    cout << ans << '\n';
    return 0;
}
