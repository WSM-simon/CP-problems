#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ar3 array<int, 3>
#define f first
#define s second

using namespace std;

const int Max = 1e2 + 3;

int N, e[Max];
set<ar3> penList;                 // penList is used for kruskal.
set<pii> edgeAdded;               // if an edge is in edgeAdded, means it is between two pens, which is not an outer edge.
map<pii, int> edgeCost, edgeUsed; // edgeUsed is only for input, no need for the searching

void input()
{
    cin >> N;
    for (int n = 1; n <= N; ++n)
    {
        int p;
        vector<int> edges, costs;
        cin >> p;
        for (int i = 0; i < p; ++i)
        {
            int edge;
            cin >> edge;
            edges.push_back(edge);
        }
        for (int i = 0; i < p; ++i)
        {
            int cost;
            cin >> cost;
            costs.push_back(cost);
        }
        for (int i = 0; i < p; ++i)
        {
            int k = i, j = i == p - 1 ? 0 : i + 1;
            int i2 = edges[i], j2 = edges[j];
            if (i2 > j2)
                swap(i2, j2);
            if (edgeUsed.find({i2, j2}) == edgeUsed.end())
                edgeUsed[{i2, j2}] = n;
            else
            {
                int a = n, b = edgeUsed[{i2, j2}], cost = edgeCost[{i2, j2}];
                // a and b here are not points, they are pens(animals)
                if (a > b)
                    swap(a, b);
                edgeAdded.insert({i2, j2});
                penList.insert({cost, a, b});
            }
            edgeCost[{i2, j2}] = costs[k];
        }
    }
}

int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

bool same(int x, int y) { return get(x) == get(y); }

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

int kruskal()
{
    int cost = 0;
    fill(e, e+Max, -1);
    for (ar3 pen:penList)
        if (unite(pen[1], pen[2]))
            cost += pen[0];
    
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    int ans1, ans2;
    ans1 = kruskal();

    // set the outside as pen 0.
    for (pair<pii, int> edge : edgeUsed)
        if (edgeAdded.find(edge.f) == edgeAdded.end())
            penList.insert({edgeCost[{edge.f.f, edge.f.s}], 0, edge.s});

    // the second search include pen 0, which means all the animals will go gather outside.
    ans2 = kruskal();

    cout << min(ans1, ans2);
    return 0;
}