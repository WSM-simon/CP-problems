#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e3 + 3;
const int MxM = 1e5 + 3;

int N, M, m1[4] = {1, 0, -1, 0}, m2[4] = {0, 1, 0, -1};
char graph[MxN][MxN], e[4] = {'D', 'R', 'U', 'L'};

struct node {
    int x;
    int y;
} st, ed;

vector<char> path;
bool valid(node n) {
    return (n.x >= 0 && n.x < N && n.y >= 0 && n.y < M && graph[n.x][n.y] != '#');
}
bool dfs(node n) {
    if (graph[n.x][n.y] == 'B') return 1;
    graph[n.x][n.y] = '#';
    for (int i = 0; i < 4; ++i) {
        node nxt = {n.x + m1[i], n.y + m2[i]};
        if (!valid(nxt))
            continue;
        if (dfs(nxt)) {
            path.push_back(e[i]);
            return 1;
        }
    }
    graph[n.x][n.y] = '.';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            char tem;
            cin >> tem;
            graph[i][j] = tem;
            if (tem == 'A')
                st = {i, j};
            if (tem == 'B')
                ed = {i, j};
        }
    if (dfs(st)) {
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (char x : path)
            cout << x;
    }

    return 0;
}