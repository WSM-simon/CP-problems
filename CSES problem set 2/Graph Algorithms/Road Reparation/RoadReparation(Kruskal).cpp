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

int N, M, e[Max];
// set is slower than vector, don't use it
vector<ar3> edges;

int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    ll res = 0;
    int cnt = 0;
    memset(e, -1, sizeof(e));
    for (ar3 arr : edges)
        if (unite(arr[1], arr[2]))
            res += arr[0], cnt++;
    if (cnt == N - 1)
        cout << res << '\n';
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}
