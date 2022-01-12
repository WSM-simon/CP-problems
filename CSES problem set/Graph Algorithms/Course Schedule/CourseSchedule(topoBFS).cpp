#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M;
int inD[Max];
vector<int> path[Max];
queue<int> q;

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
        ++inD[v2];
    }

    for (int i = 1; i <= N; ++i)
        if (!inD[i])
            q.push(i);

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int v : path[node])
            if (--inD[v] == 0)
                q.push(v);
    }

    if (ans.size() != N)
        cout << "IMPOSSIBLE";
    else
        for (int v : ans)
            cout << v << ' ';
    return 0;
}