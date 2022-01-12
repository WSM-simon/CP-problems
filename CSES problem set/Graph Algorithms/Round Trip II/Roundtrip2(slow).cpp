#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e1 + 3;
int N, M, par[Max];
bool vis[Max];
vector<int> path[Max];

void retrace(int v, int n)
{
    int v2 = v;
    vector<int> ans;
    ans.push_back(n);
    while (v2 != n)
    {
        ans.push_back(v2);
        v2 = par[v2];
    }
    ans.push_back(n);

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';

    exit(0);
}

int target = -1;
void dfs(int v, int pre = -1)
{
    vis[v] = 1;
    par[v] = pre;
    for (int n : path[v])
    {
        if (n == target && n != v)
            retrace(v, n);

        if (vis[n])
            continue;
        dfs(n, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        path[v1].push_back(v2);
    }

    for (int i = 1; i <= N; ++i)
    {
        target = i;
        dfs(i);
    }

    cout << "IMPOSSIBLE";
    return 0;
}