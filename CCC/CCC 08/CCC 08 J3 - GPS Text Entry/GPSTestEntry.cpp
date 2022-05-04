#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
map<string, pii> grid = {
    {"A", {0, 0}},
    {"B", {0, 1}},
    {"C", {0, 2}},
    {"D", {0, 3}},
    {"E", {0, 4}},
    {"F", {0, 5}},
    {"G", {1, 0}},
    {"H", {1, 1}},
    {"I", {1, 2}},
    {"J", {1, 3}},
    {"K", {1, 4}},
    {"L", {1, 5}},
    {"M", {2, 0}},
    {"N", {2, 1}},
    {"O", {2, 2}},
    {"P", {2, 3}},
    {"Q", {2, 4}},
    {"R", {2, 5}},
    {"S", {3, 0}},
    {"T", {3, 1}},
    {"U", {3, 2}},
    {"V", {3, 3}},
    {"W", {3, 4}},
    {"X", {3, 5}},
    {"Y", {4, 0}},
    {"Z", {4, 1}},
    {"space", {4, 2}},
    {"-", {4, 3}},
    {".", {4, 4}},
    {"enter", {4, 5}},
};

int manhattan_dis(pii a, pii b) { return abs(a.first - b.first) + abs(a.second - b.second); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pii now = {0, 0};
    int cnt = 0;
    string s;
    cin >> s;
    for (char c : s)
    {
        string cs(1, c);
        cnt += manhattan_dis(now, grid[cs]);
        now = grid[cs];
    }
    while (cin >> s)
    {
        cnt += manhattan_dis(now, grid["space"]);
        now = grid["space"];
        for (char c : s)
        {
            string cs(1, c);
            cnt += manhattan_dis(now, grid[cs]);
            now = grid[cs];
        }
    }
    cnt += manhattan_dis(now, grid["enter"]);
    now = grid["enter"];
    cout << cnt << '\n';
    return 0;
}
