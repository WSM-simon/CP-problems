#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N;

int SDR(string s)
{
    int total = 0;
    for (char c:s)
        total += (c-'0');
    string ss = to_string(total);
    if (ss.size() != 1)
        return SDR(ss);
    else
        return total;
}
void solve()
{
    string s;
    cin >> s;
    cout << SDR(s) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while(N--)
        solve();
    return 0;
}
