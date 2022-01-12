#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
// #define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

using namespace std;

const int Max = 1001;
int M, N;
unordered_set<int> vis;
vector<int> path[Max * Max];

bool bfs(int st, int ed)
{
    queue<int> q;
    q.push(st);
    vis.insert(st);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        vector<int> nextN = path[node];
        for (int i : nextN)
        {
            if (i == ed)
                return true;
            if (vis.find(i) == vis.end())
            {
                q.push(i);
                vis.insert(i);
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    int ed=1, st = M * N;

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        {

            int tem;
            cin >> tem;
            path[tem].push_back(i * j);
        }

    if (bfs(st, ed))
        cout << "yes";
    else
        cout << "no";
    return 0;
}