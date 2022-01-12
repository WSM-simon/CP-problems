#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 5e5 + 3;
ll N, M, e[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> e[1];
    for (int i = 2; i <= N; ++i)
    {
        ll v;
        cin >> v;
        e[i] = e[i - 1] + v;
    }
    for (int i = 0; i < M; ++i)
    {
        ll p1, p2;
        cin >> p1 >> p2;
        cout << e[p2] - e[p1] << '\n';
    }

    return 0;
}