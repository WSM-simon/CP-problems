#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 1;
int n, m, parent[Max];
bool vis[Max];
vector<int> graph[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int tem1, tem2;
        cin >> tem1 >> tem2;
        graph[tem1].push_back(tem2);
        graph[tem2].push_back(tem1);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == n)
            break;

        for (int p : graph[v])
        {
            if (!vis[p])
            {
                vis[p] = 1;
                parent[p] = v;
                q.push(p);
            }
        }
    }

    if (vis[n] == 1)
    {
        stack<int> ans;
        int ed = n;
        while (ed != 1)
        {
            ans.push(ed);
            ed = parent[ed];
        }
        ans.push(1);
        
        cout << ans.size() << '\n';

        while (!ans.empty())
        {
            cout << ans.top() << ' ';
            ans.pop();
        }
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}