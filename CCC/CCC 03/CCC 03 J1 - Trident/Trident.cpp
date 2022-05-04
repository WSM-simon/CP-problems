#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int t, s, h;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> s >> h;

    for (int i = 0; i < t; ++i)
    {
        cout << '*';
        for (int j = 0; j < s; ++j)
            cout << ' ';
        cout << '*';
        for (int j = 0; j < s; ++j)
            cout << ' ';
        cout << "*\n";
    }
    for (int i=0; i<3+2*s; ++i)
        cout << '*';
    cout << '\n';
    for (int i=0; i<h; ++i)
    {
        for (int j=0; j<1+s; ++j)
            cout << ' ';
        cout << "*\n";
    }

    return 0;
}
