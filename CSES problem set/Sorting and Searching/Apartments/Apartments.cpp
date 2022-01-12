#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m, k, a[200001], b[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && b[j] < a[i] - k)
            j++;
        if (j >= m)
            break;
        if (b[j] <= a[i] + k)
            j++, ans++;
    }
    cout << ans;
    return 0;
}