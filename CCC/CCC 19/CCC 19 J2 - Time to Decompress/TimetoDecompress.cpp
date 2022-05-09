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

    cin >> N;
    for (int i=0; i<N; ++i)
    {
        int tem;
        char c;
        cin >> tem;
        cin >> c;
        for (int i=0; i<tem; ++i)
            cout << c;
        cout << '\n';
    }
    return 0;
}
