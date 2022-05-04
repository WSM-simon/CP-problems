#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

bool solve(int y, int m, int d)
{
    int adult_y = y+18;
    if (adult_y < 2007)
        return 1;
    if (adult_y == 2007)
    {
        if (m < 2)
            return 1;
        if (m == 2)
        {
            if (d <= 27)
                return 1;
            return 0;
        }
        return 0;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while(N--)
    {
        int year, month, day;
        cin >> year >> month >> day;
        if (solve(year, month, day))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
