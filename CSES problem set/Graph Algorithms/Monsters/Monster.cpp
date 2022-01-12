#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 1003;
const int inf = INT_MAX;

int N, M, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char step[4] = {'D', 'R', 'U', 'L'};

int paths[Max][Max], moveStep[Max][Max];
queue<pii> q;
pii st;

bool isValid(pii node, pii nextN) { return (paths[node.f][node.s] + 1 < paths[nextN.f][nextN.s]); }

bool found(pii node) { return (node.f == 1 || node.f == N || node.s == 1 || node.s == M); }

void bfs(bool monster = 0)
{
    while (!q.empty())
    {
        pii node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pii nextN = pii(node.f + dx[i], node.s + dy[i]);
            if (isValid(node, nextN))
            {
                q.push(nextN);
                paths[nextN.f][nextN.s] = paths[node.f][node.s] + 1;
                moveStep[nextN.f][nextN.s] = i;
            }
        }
        if (!monster && found(node))
        {
            cout << "YES"
                 << "\n";

            vector<char> ans;
            while (node != st)
            {
                int m = moveStep[node.f][node.s];
                ans.push_back(step[m]);
                node = pii(node.f - dx[m], node.s - dy[m]);
            }
            cout << ans.size() << '\n';
            while (!ans.empty())
            {
                cout << ans.back();
                ans.pop_back();
            }

            exit(0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char tem;
            cin >> tem;
            if (tem == '#')
                continue;
            else if (tem == 'M')
                q.push(pii(i, j));
            else if (tem == 'A')
                st = pii(i, j);
            else
                paths[i][j] = inf;
        }
    }
    paths[st.f][st.s] = inf;
    bfs(true);

    moveStep[st.f][st.s] = -1;
    paths[st.f][st.s] = 0;
    q.push(st);
    bfs(false);

    cout << "NO";
    return 0;
}