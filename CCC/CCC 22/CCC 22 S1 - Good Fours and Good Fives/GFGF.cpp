#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int a = N / 4;
    int b = N % 4;
    if (a < b)
    {
        cout << "0\n";
        return 0;
    }
    a -= b;
    cout << 1 + a / 5 << '\n';
    return 0;
}