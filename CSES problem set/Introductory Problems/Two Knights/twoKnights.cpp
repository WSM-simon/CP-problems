#include <bits/stdc++.h>
#define ll long long
#define pii pair<int int>


using namespace std;

int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i < n+1; i++)
    {
        ll All = i * i;
        ll ans = All * (All - 1) / 2;
        if (i > 2)
            ans -= 4 * (i-1)*(i-2);
        // https://www.youtube.com/watch?v=DGgxDjpTzhk explains why ans -= 4 * (i-1)*(i-2)

        cout << ans << '\n'; 
    }

    return 0;
}