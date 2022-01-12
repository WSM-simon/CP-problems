#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define arr array
#define f first
#define s second

using namespace std;

const int Max = 1e4 + 3;
int C, R, D;
bool vis[Max];
unordered_map<int, int> dest;
vector<arr<int, 3>> path;
vector<pii> path2[Max];
vector<int> e;

bool comp(const arr<int, 3> a, const arr<int, 3> b) { return a[0] > b[0]; }

int get(int x) { return (e[x] < 0 ? x : get(e[x])); }

bool unite(int x, int y)
{
    x = get(x), y = get(y);
    if (x == y)
        return 0;
    if (e[x] > e[y])
        swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
}

void dfs(int n, int w = INT_MAX)
{
    for (pii v : path2[n])
    {
        if (vis[v.f])
            continue;
        vis[v.f] = 1;
        if (dest.find(v.f) != dest.end())
            dest[v.f] = min(w, v.s);

        dfs(v.f, min(w, v.s));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C >> R >> D;
    e = vector<int>(C + 1, -1);

    for (int i = 0; i < R; ++i)
    {
        int e1, e2, d;
        cin >> e1 >> e2 >> d;
        path.push_back({d, e1, e2});
        // dis, e1, e2
    }

    sort(path.begin(), path.end(), comp);

    for (int i = 0; i < D; ++i)
    {
        int c;
        cin >> c;
        dest.insert({c, 0});
    }

    for (auto v : path)
        if (unite(v[1], v[2]))
        {
            path2[v[1]].push_back({v[2], v[0]});
            path2[v[2]].push_back({v[1], v[0]});
        }

    dfs(1);
    int ans = INT_MAX;
    for (auto v : dest)
        ans = min(ans, v.s);
    cout << ans;
    return 0;
}