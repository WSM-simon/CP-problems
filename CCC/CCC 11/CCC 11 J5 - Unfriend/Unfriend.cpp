#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 10;

int N, M, cnt[Max];
vector<int> adj[Max];

void dfs(int n)
{
    cnt[n] = 1;
    for (int v : adj[n])
    {
        dfs(v);
        cnt[n] *= cnt[v]+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N - 1; ++i)
    {
        int v;
        cin >> v;
        adj[v].push_back(i);
    }

    dfs(N);
    cout << cnt[N];
    return 0;
}