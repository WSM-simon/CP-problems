#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;

int N, d[Max], leaf[Max];
vector<int> adj[Max];

// void dfs(int n, int p)
// {
//     for (int v:adj[n])
//     {
//         if (v != p)
//         {
//             d[v] =
//         }
//     }
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    // dfs(1, -1);
    return 0;
}