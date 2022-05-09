#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5;
int N, dp[Max];
vector<int> adj[Max];
bool vis[Max];

void dfs(int n)
{
    for(int v:adj[n])
    {
        if (!vis[v])
        {
            vis[v]=1;    
            dfs(v);
        }
        dp[n]+=dp[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int v1, v2;
    cin >> v1 >> v2;
    while(v1!=0)
    {
        adj[v1].push_back(v2);
        cin >> v1 >> v2;   
    }
    dp[N]=1;
    dfs(N);
    cout << dp[1];
    return 0;
}