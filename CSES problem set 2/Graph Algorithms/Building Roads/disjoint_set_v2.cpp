#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;

int N, M, cnt = 0, e[Max];

int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

bool same(int x, int y) { return get(x) == get(y); }

bool unite(int x, int y)
{
    x = get(x), y = get(y);
    if (same(x, y))
        return 0;
    if (e[x] > e[y])
        swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(e, -1, sizeof(e));

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        unite(v1, v2);
    }
    vector<int> ans;
    for (int i = 1; i <= N; ++i)
        if (e[i] < 0)
            ans.push_back(i);

    int sz = ans.size();
    cout << sz - 1 << '\n';
    for (int i = 0; i < sz - 1; ++i)
        cout << ans[i] << ' ' << ans[i + 1] << '\n';

    return 0;
}