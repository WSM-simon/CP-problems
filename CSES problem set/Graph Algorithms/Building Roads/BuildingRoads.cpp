#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 1;
int n, m;
bool vis[Max];
vector<int> graph[Max];

void dfs(int n)
{
    for (int i : graph[n])
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
        }
}

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

    int cnt = -1;
    vector<int> roads;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            roads.push_back(i);
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << '\n';
    for (int i = 0; (size_t)i < roads.size() - 1; i++)
        cout << roads[i] << ' ' << roads[i + 1] << '\n';

    return 0;
}