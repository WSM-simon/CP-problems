#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200001;
pii arr[Max];

bool sortPii(pii p1, pii p2) { return p1.second < p2.second; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + n, sortPii);

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (arr[i].first >= j)
        {
            j = arr[i].second;
            ans++;
        }
    }

    cout << ans;
    return 0;
}