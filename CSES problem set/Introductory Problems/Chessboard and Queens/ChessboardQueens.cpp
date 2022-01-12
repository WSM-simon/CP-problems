#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

/*
col represent the column we are placing the queen;
and the "i" in each for loop represent the row we are working on.

here i use one array to represent both two directions of diagonals

one looks like ////
the other looks like \\\\
each one has 15 lines.

the formula of // is (r+c)
and the formula of \\ is (r+7-c)
*/

string s[8];
bool diag[15];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 8; i++)
        cin >> s[i];

    int col[8], ans = 0;
    iota(col, col + 8, 0);

    do
    {
        bool work = 1;
        for (int i = 0; i < 8; i++)
        {
            if (s[i][col[i]] != '.')
            {
                work = 0;
                break;
            }
        }
            
        // if we find the place we will put the queen in advance, we can jump to the next pattern

        if (work)
        {
            memset(diag, 0, 15);
            for (int i = 0; i < 8; i++)
            {
                if (diag[i + col[i]])
                {
                    work = 0;
                    break;
                }
                else
                    diag[i + col[i]] = 1;
            }

            memset(diag, 0, 15);
            for (int i = 0; i < 8; i++)
            {
                if (diag[i + 7 - col[i]])
                {
                    work = 0;
                    break;
                }
                else
                    diag[i + 7 - col[i]] = 1;
            }
        }

        ans += work;
    } while (next_permutation(col, col + 8));

    cout << ans;

    return 0;
}