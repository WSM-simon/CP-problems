#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll All = (1 + n) * n / 2;

    if (All & 1 == 1)
        cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        if (n & 1 == 1)
        {
            cout << (n / 2) + 1 << '\n';
            cout << 1 << ' ' << n - 1 << ' ';
            for (int i = 0; i < (n - 3) / 4; i++)
            {
                cout << i + 2 << ' ';
                cout << n - i - 2 << ' ';
            }
            cout << '\n';

            cout << (n / 2) << '\n';
            cout << n << ' ';
            for (int i = (n - 3) / 4; i < (n - 3) / 2; i++)
            {
                cout << i + 2 << ' ';
                cout << n - i - 2 << ' ';
            }
        }
        else
        {
            cout << (n / 2) << '\n';
            for (int i = 0; i < n / 4; i++)
            {
                cout << i + 1 << ' ';
                cout << n - i << ' ';
            }
            cout << '\n';

            cout << (n / 2) << '\n';
            for (int i = n / 4; i < n / 2; i++)
            {
                cout << i + 1 << ' ';
                cout << n - i << ' ';
            }
        }
    }
    return 0;
}