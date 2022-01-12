#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int x, n;
set<int> lights;
multiset<int> lengths;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> n;

    lights.insert(0);
    lights.insert(x);
    lengths.insert(x);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto s = lights.upper_bound(p), f = prev(s);
        lights.insert(p);
        lengths.erase(lengths.find(*s - *f));
        lengths.insert(p - *f);
        lengths.insert(*s - p);

        cout << *lengths.rbegin() << ' ';
    }

    return 0;
}