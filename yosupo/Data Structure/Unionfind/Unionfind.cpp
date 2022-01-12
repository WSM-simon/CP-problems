#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N, Q;
struct DSU
{
    vector<int> e;
    DSU(int N) { e = vector<int>(N + 1, -1); }

    int find(int x) { return e[x] < 0 ? x : find(e[x]); }

    bool isSame(int i, int j) { return find(i) == find(j); }

    void unite(int i, int j)
    {
        int ei = find(i), ej = find(j);
        if (ei == ej)
            return;
        else if (e[ei] < e[ej])
            e[ei] += e[ej], e[ej] = ei;
        else
            e[ej] += e[ei], e[ei] = ej;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    DSU dsu(N);

    for (int i = 0; i < Q; i++)
    {
        int q, t1, t2;
        cin >> q >> t1 >> t2;
        if (q == 0)
            dsu.unite(t1, t2);
        else
        {
            if (dsu.isSame(t1, t2))
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}