#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 1e6 + 3;
int N, M;
vector<int> adj[Max];
bool vis[Max];

bool bfs(int a, int b)
{
    memset(vis, 0, sizeof(vis));

    queue<int> q;
    q.push(a);
    vis[a] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int v : adj[node])
        {
            if (!vis[v])
            {
                if (v == b)
                    return true;

                vis[v] = 1;
                q.push(v);
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
    }

    int a, b;
    cin >> a >> b;

    if (bfs(a, b))
        cout << "yes";
    else if (bfs(b, a))
        cout << "no";
    else
        cout << "unknown";
        
    return 0;
}