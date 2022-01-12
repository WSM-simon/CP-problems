#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N;
vector<int> d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    d = vector<int>(N);
    iota(d.begin(), d.end(), 1);

    int p=0, n=0, cnt=0;
    while (n < N)
    {
        if (d[p] != 0)
        {
            ++cnt;
            if (cnt>=2)
            {
                cout << d[p] << ' ';
                cnt=0, d[p]=0, ++n;   
            }   
        }
        ++p;
        if (p>=N)
            p=0;
    }

    return 0;
}