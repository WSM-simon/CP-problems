#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 203;

int N, A, B, orderA[MxN], orderB[MxN];
int check[5][5] = {
    {0, -1, 1, 1, -1},
    {1, 0, -1, 1, -1},
    {-1, 1, 0, -1, 1},
    {-1, -1, 1, 0, 1},
    {1, 1, -1, -1, 0},
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> B;
    for (int i = 0; i < A; ++i)
        cin >> orderA[i];
    for (int i = 0; i < B; ++i)
        cin >> orderB[i];

    int sa = 0, sb = 0;
    int pa = 0, pb = 0;
    for (int i = 0; i < N; ++i)
    {
        // judging the outcome of a round

        // A wins
        if (check[orderA[pa]][orderB[pb]] == 1)
            sa++;
        else if (check[orderA[pa]][orderB[pb]] == -1)
            sb++;
        if (pa == A - 1)
            pa = 0;
        else
            pa++;
        if (pb == B - 1)
            pb = 0;
        else
            pb++;
    }
    cout << sa << ' ' << sb;
    return 0;
}
