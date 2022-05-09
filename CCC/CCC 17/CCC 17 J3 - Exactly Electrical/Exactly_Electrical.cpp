#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, t, sd = 0, st = 0;
    cin >> a >> b >> c >> d >> t;

    int dis = abs(c - a) + abs(d - b);
    if (dis % 2 == 1)
        sd = 1;
    if (t % 2 == 1)
        st = 1;
    if (sd == st && t >= dis)
        cout << 'Y' << '\n';
    else
        cout << 'N' << '\n';
    return 0;
}