#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200001;
int arr[Max];
map<int, bool> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans=0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && mp[arr[j]] == 0)
        {
            mp[arr[j]] = 1;
            j++;
        }
        ans=max(ans, j-i);
        mp[arr[i]] = 0;
    }

    cout << ans;
    return 0;
}