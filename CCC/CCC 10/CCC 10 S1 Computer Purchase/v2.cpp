#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int N;
vector<pair<string, int>> e;

bool comp(const pair<string, int> p1, const pair<string, int> p2)
{
    if (p1.s != p2.s)
        return p1.s > p2.s;
    else
        return p1.f < p2.f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if (N == 0)
        return 0;
    for (int i = 0; i < N; ++i)
    {
        string s;
        int R, S, D;
        cin >> s;
        cin >> R >> S >> D;
        e.push_back({s, 2 * R + 3 * S + D});
    }
    sort(e.begin(), e.end(), comp);
    for (int i = 0; i < min((size_t)2, e.size()); ++i)
        cout << e[i].f << '\n';
    return 0;
}