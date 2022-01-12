#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second

const int Max = 1001;

int n, m;
pii st, ed;
char graph[Max][Max];
char preStep[Max][Max];
int m1[4] = {1, 0, -1, 0}, m2[4] = {0, 1, 0, -1};
string step = "DRUL";

bool isVaild(int i, int j) { return graph[i][j] != '#' && i >= 0 && i < n && j >= 0 && j < m; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char tem;
            cin >> tem;
            graph[i][j] = tem;

            if (tem == 'A')
                st = {i, j};
            else if (tem == 'B')
                ed = {i, j};
        }

    queue<pii> q;
    bool found = 0;
    q.push(st);
    graph[st.f][st.s] = '#';

    while (!q.empty())
    {
        pii node = q.front();
        q.pop();

        if (node == ed)
        {
            found = 1;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            pii nextN = {node.f + m1[i], node.s + m2[i]};
            if (!isVaild(nextN.f, nextN.s))
                continue;
            q.push(nextN);
            graph[nextN.f][nextN.s] = '#';
            preStep[nextN.f][nextN.s] = i;
        }
    }

    if (found)
    {
        cout << "YES\n";
        stack<int> ans;
        while (st != ed)
        {
            int p = preStep[ed.f][ed.s];
            ans.push(p);
            ed = pii{ed.f - m1[p], ed.s - m2[p]};
        }

        cout << ans.size() << '\n';
        while (!ans.empty())
        {
            cout << step[ans.top()];
            ans.pop();
        }
    }
    else
        cout << "NO";
    return 0;
}