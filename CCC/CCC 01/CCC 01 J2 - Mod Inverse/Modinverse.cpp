#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int x, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> m;
    for (int n = 1; n <= m; ++n)
    {
        if (x * n % m == 1)
        {
            cout << n << '\n';
            return 0;
        }
    }
    cout << "No such integer exists.\n";
    return 0;
}
