#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll arr[2000];

set<ll> st;
vector<ll> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ll first, last;
    for (ll i = 0; i < N; ++i)
    {
        ll tem;
        cin >> tem;
        if (i == 0)
            first = tem;
        if (i == N - 1)
            last = tem;
        st.insert(tem);
    }
    for (ll i : st)
    {
        if (i == first)
            continue;
        ll itv = i - first;
        if (itv > 100000)
            break;
        for (ll j = first; j <= last; j += itv)
        {
            if (st.find(j) == st.end())
            {
                break;
            }
            if (j + itv > last)
                ans.push_back(j + itv);
        }
    }
    cout << *min_element(ans.begin(), ans.end()) << '\n';
    return 0;
}
