#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

map<int, int> hashmap;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tar;
    cin >> n >> tar;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        if (hashmap.find(tar - t) != hashmap.end())
        {
            cout << i + 1 << ' ' << hashmap[tar - t] + 1;
            return 0;
        }
        hashmap.insert({t, i});
    }
    
    cout << "IMPOSSIBLE";

    return 0;
}