#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

char graph[102][102];
bool vis[102][102];
int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i=1; i<N; ++i)
        for (int j=1; j<M; ++j)
            cin >> graph[i][j];
    
    
    return 0;
}