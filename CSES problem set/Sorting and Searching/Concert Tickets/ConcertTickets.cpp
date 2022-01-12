#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200001;
multiset<int> a;
int n, m, b[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        a.insert(tem);
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
    {
        int t = b[i];
        auto it = a.upper_bound(t);
        if (it != a.begin())
        {
            it--;
            cout << *it << '\n';
            a.erase(it);
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}