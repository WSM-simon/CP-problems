#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

char graph[102][102];
bool vis[102][102];
set<pii> camera;
map<pii, int> ceils;
map<pii, pii> cvyor;

void setCamera()
{
    vector<pii> unvaild;
    for (pii p : camera)
    {
        graph[p.first][p.second] = 'W';

        int cx = p.first, cy = p.second;
        while (graph[++cx][cy] != 'W')
            if (cvyor.find({cx, cy}) == cvyor.end())
                unvaild.push_back({cx, cy});

        cx = p.first, cy = p.second;
        while (graph[--cx][cy] != 'W')
            if (cvyor.find({cx, cy}) == cvyor.end())
                unvaild.push_back({cx, cy});

        cx = p.first, cy = p.second;
        while (graph[cx][++cy] != 'W')
            if (cvyor.find({cx, cy}) == cvyor.end())
                unvaild.push_back({cx, cy});

        cx = p.first, cy = p.second;
        while (graph[cx][--cy] != 'W')
            if (cvyor.find({cx, cy}) == cvyor.end())
                unvaild.push_back({cx, cy});
    }
    for (pii p : unvaild)
        graph[p.first][p.second] = 'W';
}

pii cvyorMove(pii node)
{
    set<pii> seen;
    while (cvyor.find(node) != cvyor.end())
    {
        if (seen.find(node) != seen.end())
            node = {-1, -1};
        else
        {
            vis[node.first][node.second] = 1;
            seen.insert(node);
            node = cvyor[node];
        }
    }

    return node;
}

bool isVaild(int nx, int ny)
{
    if (cvyor.find({nx, ny}) != cvyor.end())
    {
        pii node = cvyorMove({nx, ny});
        if (node == pii{-1, -1})
            return 0;
        nx = node.first;
        ny = node.second;
    }

    return (!vis[nx][ny] && graph[nx][ny] != 'W');
}

pii nextStep(int nnx, int nny, int dist)
{
    pii nextN = {nnx, nny};
    if (cvyor.find(nextN) != cvyor.end())
    {
        nextN = cvyorMove({nnx, nny});
        if (isVaild(nextN.first, nextN.second))
        {
            if (ceils.find(nextN) != ceils.end())
                ceils[nextN] = dist;

            vis[nextN.first][nextN.second] = 1;
            return nextN;
        }
    }
    if (ceils.find(nextN) != ceils.end())
        ceils[nextN] = dist;

    vis[nextN.first][nextN.second] = 1;
    return nextN;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    pii st;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
        {
            char tem;
            cin >> tem;
            graph[i][j] = tem;
            if (tem == 'S')
            {
                st.first = i;
                st.second = j;
            }
            else if (tem == '.')
                ceils.insert({{{i, j}, -1}});
            else if (tem == 'C')
                camera.insert({i, j});
            else if (tem == 'L')
                cvyor.insert({{i, j}, {i, j - 1}});
            else if (tem == 'R')
                cvyor.insert({{i, j}, {i, j + 1}});
            else if (tem == 'U')
                cvyor.insert({{i, j}, {i - 1, j}});
            else if (tem == 'D')
                cvyor.insert({{i, j}, {i + 1, j}});
        }

    setCamera();
    if (graph[st.first][st.second] == 'W')
    {
        for (pair<pii, int> pp : ceils)
            cout << pp.second << '\n';
        return 0;
    }
    //  如果出生在camera下， 所以ceil都为-1

    queue<pii> q;
    q.push(st);
    vis[st.first][st.second] = 1;

    int dist = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        dist++;
        for (int i = 0; i < qSize; i++)
        {
            pii node = q.front();
            q.pop();

            int nx = node.first, ny = node.second;
            if (isVaild(nx + 1, ny))
                q.push(nextStep(nx + 1, ny, dist));
            if (isVaild(nx - 1, ny))
                q.push(nextStep(nx - 1, ny, dist));
            if (isVaild(nx, ny + 1))
                q.push(nextStep(nx, ny + 1, dist));
            if (isVaild(nx, ny - 1))
                q.push(nextStep(nx, ny - 1, dist));
        }

    }
    for (pair<pii, int> pp : ceils)
            cout << pp.second << '\n';
}
