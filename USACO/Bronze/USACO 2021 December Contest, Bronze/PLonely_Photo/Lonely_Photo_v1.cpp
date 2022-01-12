#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 5e5 + 3;
int N;
ll cnt = 0;
char cows[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> cows[i];

    for (int i = 0; i < N; ++i)
    {
        char c = cows[i];
        ll x = i, cntL = 0, cntR = 0;
        //search for the left side differnt cows.
        while (--x >= 0)
        {
            if (cows[x] == c)
                break;
            else
                cntL++;
        }
        // back to the cow, and search for the right side different cows.
        x = i;
        while (++x < N)
        {
            if (cows[x] == c)
                break;
            else
                cntR++;
        }
        ll add = 0;
        if (cntL >= 2)
            add += cntL - 1;
        if (cntR >= 2)
            add += cntR - 1;
        add += cntL * cntR;

        cnt += add;
    }
    cout << cnt;
    return 0;
}