#include <bits/stdc++.h>
#include <experimental/random>
#define ll long long

using namespace std;

const int N = 4;
const ll inf = 1e18 + 3;
const ll MIN = -1e9;
const ll MAX = 1e9;

vector<vector<ll>> grid(N, vector<ll>(N, inf));

bool solveRow(int r, vector<vector<ll>> &g, int row[N], int col[N]) {
    ll &x = g[r][1], &y = g[r][2], &z = g[r][3];
    if (x == inf) {
        x = 2 * y - z, row[r]++, col[1]++;
        if (x < MIN || x > MAX) return 0;
    } else if (y == inf) {
        if ((x + z) % 2) return 0;
        y = (x + z) / 2, row[r]++, col[2]++;
        if (y < MIN || y > MAX) return 0;
    } else if (z == inf) {
        z = (2 * y - x), row[r]++, col[3]++;
        if (z < MIN || z > MAX) return 0;
    }
    return 1;
}

bool solveCol(int c, vector<vector<ll>> &g, int row[N], int col[N]) {
    ll &x = g[1][c], &y = g[2][c], &z = g[3][c];
    if (x == inf) {
        x = 2 * y - z, row[1]++, col[c]++;
        if (x < MIN || x > MAX) return 0;
    } else if (y == inf) {
        if ((x + z) % 2) return 0;
        y = (x + z) / 2, row[2]++, col[c]++;
        if (y < MIN || y > MAX) return 0;
    } else if (z == inf) {
        z = (2 * y - x), row[3]++, col[c]++;
        if (z < MIN || z > MAX) return 0;
    }
    return 1;
}

bool solve(vector<vector<ll>> g) {
    // find how many numbers on each row and col
    int row[N] = {}, col[N] = {};
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (g[i][j] != inf) row[i]++, col[j]++;

    // loop until there is no 2_in_1
    bool found = 0;
    do {
        found = 0;
        for (int i = 1; i < N; ++i) {
            if (row[i] == 2) {
                if (solveRow(i, g, row, col))
                    found = 1;
                else
                    return 0;
            }
        }
        for (int i = 1; i < N; ++i) {
            if (col[i] == 2) {
                if (solveCol(i, g, row, col))
                    found = 1;
                else
                    return 0;
            }
        }
    } while (found);
    grid = g;
    // check if finish
    for (int i = 1; i < N; ++i)
        if (row[i] != 3) return 0;
    for (int i = 1; i < N; ++i)
        if (col[i] != 3) return 0;
    return 1;
}

ll MyRandom() {
    return experimental::randint(MIN, MAX) % (ll)1e8;
}

void randomGrid(vector<vector<ll>> &g) {
    int row[N] = {}, col[N] = {};
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (g[i][j] != inf) row[i]++, col[j]++;

    for (int i = 1; i < N; ++i) {
        if (row[i] == 1)
            for (int j = 1; j < N; ++j)
                if (g[i][j] == inf) {
                    g[i][j] = MyRandom();
                    return;
                }
        if (col[i] == 1)
            for (int j = 1; j < N; ++j)
                if (g[j][i] == inf) {
                    g[j][i] = MyRandom();
                    return;
                }
    }
    // if there is no number on grid, all "X"
    g[1][1] = MyRandom(), g[1][2] = MyRandom();
    return;
}

void myPrint() {
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (grid[i][j] == inf)
                cout << 'X';
            else
                cout << grid[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            int tem;
            cin >> tem;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                continue;
            }
            grid[i][j] = tem;
        }
    }
    vector<vector<ll>> tem_grid = grid;
    while (!solve(tem_grid)) {
        tem_grid = grid;
        randomGrid(tem_grid);
    }
    myPrint();
    return 0;
}
