#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int Max = 1e5 + 3;
const int inf = 0x3f3f3f3f;

int X, Y, N;
map<string, int> mp;

vector<pair<string, string>> group;
vector<pair<string, string>> ungroup;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X;
    for (int i = 0; i < X; ++i)
    {
        string a, b;
        cin >> a >> b;
        group.push_back({a, b});
    }
    cin >> Y;
    for (int i = 0; i < Y; ++i)
    {
        string a, b;
        cin >> a >> b;
        ungroup.push_back({a, b});
    }
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;
        mp[a] = mp[b] = mp[c] = i;
    }
    int cnt = 0;
    for (auto p : group)
    {
        if (mp[p.f] != mp[p.s])
            cnt++;
    }
    for (auto p : ungroup)
    {
        if (mp[p.f] == mp[p.s])
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}