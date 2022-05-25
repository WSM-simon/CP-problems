#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a=1, b =2;
    if ((--b == 1) || a==b)
    {
        cout << "YES";
    }
    else
        cout << "NO";
    cout << "\n";
    cout << a << ' ' << b;
    return 0;
}
