#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;

int N;

// It's hard to calculate from 1 to N, but its way easier to calculate from N to 1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int cost = 0;
    while (N != 1)
    {
        int f1 = 1, f2 = 0;
        for (int i = 2; i * i <= N; ++i)
        {
            if (N % i == 0)
            {
                f1 = i, f2 = N / f1;
                break;
            }
        }
        // the smaller factor f1 is going to be cost+1
        if (f1 == 1)
        {
            cost += N - 1;
            N -= 1;
        }
        else
        {
            cost += f1 - 1;
            N = (f1 - 1) * f2;
        }
    }
    cout << cost << '\n';
    return 0;
}
