#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

void solve()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        if (n % i == 0)
            sum += i;
    sum -= n;
    cout << n;
    if (sum < n)
        cout << " is a deficient number.\n";
    if (sum == n)
        cout << " is a perfect number.\n";
    if (sum > n)
        cout << " is an abundant number.\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--)
        solve();
    return 0;
}
