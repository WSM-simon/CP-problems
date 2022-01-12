#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int const Max = 1e5 * 2 + 1;
int n, m;
ll arr[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll tem;
        cin >> tem;
        arr[i] = arr[i - 1] + tem;
    }

    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout << arr[t2] - arr[t1 - 1] << '\n';
    }

    return 0;
}