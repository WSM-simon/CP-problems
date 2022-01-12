#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 503;
int N, M, K, gn[Max];
vector<int> bg[Max];
bool vis[Max];

struct comp2
{
    bool operator()(const int a, const int b) { return gn[a] < gn[b]; }
};

struct comp1
{
    bool operator()(const pair<int, set<int, comp2>> a, const pair<int, set<int, comp2>> b) { return a.second.size() < b.second.size(); }
};

set<pair<int, set<int, comp2>>, comp1> sbg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i)
    {
        int b, g;
        cin >> b >> g;
        bg[b].push_back(g);
        gn[g]++;
    }

    for (int i = 1; i <= N; ++i)
        sbg.insert({i, set<int, comp2>(bg[i].begin(), bg[i].end())});

    vector<pair<int, int>> ans;
    for (auto v : sbg)
    {
        int boy = v.first;
        auto girls = v.second;
        for (int girl : girls)
        {
            if (!vis[girl])
            {
                vis[girl]=1;
                ans.push_back({boy, girl});
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto p:ans)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}