#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

string s;
ll ways = 0;
bool vis[10][10];

bool isvalid(int x, int y) {
    return !vis[x][y] && x >= 0 && x <= 6 && y >= 0 && y <= 6;
}

void dfs(int n, int x, int y) {
    if (n == 48) {
        ways++;
        return;
    }
    vis[x][y] = 1;
    if (s[n] == '?' || s[n] == 'U')
        if (isvalid(x, y - 1))
            if (isvalid(x, y-2) && !isvalid(x - 1, y + 1) && !isvalid(x - 1, y - 1))
                dfs(n + 1, x, y - 1);

    if (s[n] == '?' || s[n] == 'D')
        if (isvalid(x, y + 1))
            dfs(n + 1, x, y + 1);

    if (s[n] == '?' || s[n] == 'R')
        if (isvalid(x + 1, y))
            dfs(n + 1, x + 1, y);

    if (s[n] == '?' || s[n] == 'L')
        if (isvalid(x - 1, y))
            dfs(n + 1, x - 1, y);
    vis[x][y] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    dfs(0, 0, 0);
    cout << ways << '\n';
    return 0;
}
