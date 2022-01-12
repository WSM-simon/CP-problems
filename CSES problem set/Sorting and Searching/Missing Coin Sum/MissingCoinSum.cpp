#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2000001;
ll arr[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);
    ll ans=1;
    for (int i=0; i<n; i++)
        if (ans>=arr[i])
            ans+=arr[i];

    cout << ans;
}