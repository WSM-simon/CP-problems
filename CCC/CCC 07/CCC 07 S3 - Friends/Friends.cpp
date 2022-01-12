#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    unordered_map<int, int> mp;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        mp[t1] = t2;
    }

    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;

        int ans = -1, fri = a;
        bool found = 0;
        do
        {
            if (mp.find(fri) != mp.end())
            {
                fri = mp[fri];
                ans++;
                if (fri == b)
                {
                    found = 1;
                    break;
                }
            }
            else
                break;
        } while (fri != a);

        if (found)
            cout << "Yes" << ' ' << ans << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}