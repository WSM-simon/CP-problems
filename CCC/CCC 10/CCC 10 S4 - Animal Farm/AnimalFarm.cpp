#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

int N;
vector<int> e(103, -1);
map<pii, int> edgeLength; // edgePen store which pen does an edge belongs to.
map<pii, vector<int>> edgePen;
set<ar3> pens; // store length, pen1, pen2;

int get(int x) { return e[x] < 0 ? x : get(e[x]); }

int volume(int x) { return -e[x]; }

bool unite(int x, int y)
{
    x = get(x), y = get(y);
    if (x == y)
        return 0;
    if (x > y)
        swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
}

int kruskal1()
{
    int ans = 0;
    for (ar3 arr : pens)
        if (unite(arr[1], arr[2]))
            ans += arr[0];
    return ans;
}

int kruskal2()
{
    int ans = 0;
    for (ar3 arr : pens)
        if (arr[2] != N + 1)
            if (unite(arr[1], arr[2]))
                ans += arr[0];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int M;
        cin >> M;
        vector<int> ee, d;
        for (int j = 0; j < M; ++j)
        {
            int tem;
            cin >> tem;
            ee.push_back(tem);
        }
        for (int j = 0; j < M; ++j)
        {
            int tem;
            cin >> tem;
            d.push_back(tem);
        }
        for (int j = 0; j < M - 1; j++)
        {
            pii e1 = {ee[j], ee[j + 1]};
            int d1 = d[j];
            if (e1.f > e1.s)
                swap(e1.f, e1.s);
            edgePen[e1].push_back(i);
            edgeLength.insert({e1, d1});
        }
        pii e1 = {ee[0], ee[M - 1]};
        int d1 = d[M - 1];
        if (e1.f > e1.s)
            swap(e1.f, e1.s);
        edgePen[e1].push_back(i);
        edgeLength.insert({e1, d1});
    }
    // input over
    for (auto p : edgePen)
    {
        if (p.s.size() == 1)
            pens.insert({edgeLength[p.f], p.s[0], N + 1});
        else if (p.s.size() == 2)
        {
            sort(p.s.begin(), p.s.end());
            pens.insert({edgeLength[p.f], p.s[0], p.s[1]});
        }
    }
    // analysis over.
    bool out;
    int ans2 = kruskal2();
    if (volume(get(1)) != N )
        out = 1;
    fill(e.begin(), e.end(), -1);
    int ans1 = kruskal1();
    if (out || ans2 < ans1)
        cout << ans2;
    else
        cout << ans1;

    return 0;
}