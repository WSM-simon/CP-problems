#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, x, p[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);
    int ans = 0;
    for (int i = 0, j = n - 1; i < n;)
    {
        while (i < j && p[i] + p[j] > x)
            j--;
        if (i >= j)
            break;
        ans++, i++, j--;
    }

    cout << n - ans;
    return 0;
}