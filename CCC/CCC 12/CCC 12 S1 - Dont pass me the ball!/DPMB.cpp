#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 200;

ll N, C[MxN+1][MxN+1];

void Initial()
{
    int i, j;
    for (i = 0; i <= MxN; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MxN; ++i)
        for (j = 1; j <= MxN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
    
}

ll Combination(int n, int m) { return C[n][m]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Initial();
    cin >> N;
    if (N>=4)
        cout << Combination(N-1, 3) << '\n';
    else
        cout << 0 << '\n';
    return 0;
}
