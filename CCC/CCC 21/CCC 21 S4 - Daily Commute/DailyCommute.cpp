#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int inf = 0x3f3f3f3f;
const int Max = 2e5 + 3;
int N, W, D, dis[Max], sub[Max];
vector<int> adj[Max];
multiset<int> ans;

void bfs(int st)
{
    queue<int> q;
    q.push(st);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (int v : adj[n])
        {
            if (dis[v] <= dis[n])
                continue;

            dis[v] = dis[n] + 1;
            q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W >> D;

    for (int i = 0; i < W; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t2].push_back(t1);
        // reversed adj array
    }

    bfs(N);
    // count the dist between N and every single station

    for (int i = 0; i < N; ++i)
        cin >> sub[i];

    memset(dis, 0x3f, sizeof(dis));
    // set all distance to "infinity"
    dis[N] = 0;

    for (int i = 0; i < N; ++i)
    {
        if (dis[sub[i]] < inf)
        {
            int cdist = i + dis[sub[i]];
            ans.insert(cdist);
        }
    }

    for (int i = 0; i < D; ++i)
    {
        int p1, p2, cdist;
        cin >> p1 >> p2;
        --p1, --p2;

        if (dis[sub[p1]] < inf)
        {
            cdist = p1 + dis[sub[p1]];
            ans.erase(ans.find(cdist));
        }
        if (dis[sub[p2]] < inf)
        {
            cdist = p2 + dis[sub[p2]];
            ans.erase(ans.find(cdist));
        }

        swap(sub[p1], sub[p2]);

        if (dis[sub[p1]] < inf)
        {
            cdist = p1 + dis[sub[p1]];
            ans.insert(cdist);
        }
        if (dis[sub[p2]] < inf)
        {
            cdist = p2 + dis[sub[p2]];
            ans.insert(cdist);
        }

        cout << ans.f << '\n';
        // mutiset is sorted
    }
    return 0;
}