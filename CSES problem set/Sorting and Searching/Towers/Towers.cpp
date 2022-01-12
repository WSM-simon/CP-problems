#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200001;
int arr[Max];

multiset<int> towers;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {   
        auto it = towers.upper_bound(arr[i]);
        if (it != towers.end())
            towers.erase(it);      
        else
            ans++;

        towers.insert(arr[i]);
    }
    cout << ans;
    return 0;
}