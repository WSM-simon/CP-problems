#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int Max = 2e2 + 3;
const int inf = 0x3f3f3f3f;

int N, M, cost[Max];
vector<int> adj[Max];
int col[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; ++i)
    {
        char cc;
        cin >> cc;
        if (cc = 'Y')
            col[i] = 1;
    }
    for (int i = 1; i <= N; ++i)
    {
        int co;
        cin >> co;
        cost[i] = co;
    }
    
    cout << res << '\n';
    return 0;
}
