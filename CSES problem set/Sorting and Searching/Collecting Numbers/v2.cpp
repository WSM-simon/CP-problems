#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200002;
int arr[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        arr[tem] = i + 1;
    }

    int inver = 1;
    for (int i = 1; i < n; i++)
        if (arr[i + 1] < arr[i])
            inver++;

    cout << inver;
    return 0;
}