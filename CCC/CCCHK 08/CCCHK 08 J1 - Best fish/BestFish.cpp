#include <bits/stdc++.h>
#define ll long long

using namespace std;

int C, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mostC = 0, mostN = 0;
    cin >> C;
    for (int i = 0; i < C; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        mostC = max(mostC, t1 * t2);
    }
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        mostN = max(mostN, t1 * t2);
    }
    if (mostC > mostN)
        cout << "Casper\n";
    if (mostC == mostN)
        cout << "Tie\n";
    if (mostC < mostN)
        cout << "Natalie\n";
    return 0;
}
