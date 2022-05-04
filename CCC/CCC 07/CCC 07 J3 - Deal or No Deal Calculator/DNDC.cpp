#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M, total = 1691600;
int briefcases[10] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int tem;
        cin >> tem;
        total -= briefcases[tem-1];
    }
    cin >> M;
    if (M*(10 - N) > total)
        cout << "deal\n";
    else
        cout << "no deal\n";
    return 0;
}
