#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

struct Comp
{
    bool operator()(const pair<pair<char, int>, int> p1, const pair<pair<char, int>, int> p2)
    {
        return p1.second > p2.second;
    }
};

const int Max = 2 * 1e3 + 3;
int N, graph[Max][Max];
map<pair<char, int>, int, Comp> mp;
vector<pair<char, int>> steps;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int tem;
            cin >> tem;
            if (tem == 1)
            {
                graph[i][j] = 1;
                num1R[i]++, num1C[j]++;
            }
            else
                graph[i][j] = -1;
        }
    }
    // input over

    return 0;
}