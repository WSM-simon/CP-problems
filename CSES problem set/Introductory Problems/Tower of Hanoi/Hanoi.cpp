#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

void hanoi(int n, int f, int b, int t)
{
    if (n == 1)
        cout << f << ' ' << t << '\n';
    else
    {
        hanoi(n - 1, f, t, b);
        hanoi(1, f, b, t);
        hanoi(n - 1, b, f, t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << (2 << (n - 1)) - 1 << '\n';
    hanoi(n, 1, 2, 3);
    return 0;
}