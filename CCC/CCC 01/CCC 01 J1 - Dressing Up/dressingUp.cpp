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
    for (int i = 1; i <= N; i += 2)
    {
        for (int j = 1; j <= N * 2; ++j)
        {
            if (j <= i || N * 2 - j + 1 <= i)
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    for (int i = N-2; i >= 1; i -= 2)
    {
        for (int j = 1; j <= N * 2; ++j)
        {
            if (j <= i || N * 2 - j + 1 <= i)
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
