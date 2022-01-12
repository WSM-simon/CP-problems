#include <bits/stdc++.h>
#define ll long long
#define pll pair<const long long, long long>

using namespace std;

int arr[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 1;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            cnt++;
    }

    cout << cnt;
}