#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N, M;
map<int, vector<string>> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string s;
        int R, S, D;
        cin >> s;
        cin >> R >> S >> D;
        mp[2 * R + 3 * S + D].push_back(s);
    }
    int cnt;
    if (N == 0)
        return 0;
    else if (N == 1)
        cnt = 1;
    else
        cnt = 2;

    auto it = --mp.end();

    vector<string> vs = it->second;
    if (vs.size() == 1)
    {
        cout << vs[0] << '\n';
        --cnt;
    }
    else
    {
        sort(vs.begin(), vs.end());
        cout << vs[0] << '\n'
             << vs[1] << '\n';
        cnt -= 2;
    }
    if (cnt)
    {
        --it;
        vector<string> vs = it->second;
        cout << vs[0] << '\n';
    }

    return 0;
}