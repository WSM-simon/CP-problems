#include <bits/stdc++.h>
#define ll long long
#define pii pair<int int>

using namespace std;

int N;
bitset<16> code;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < (1 << N); i++)
    {
        code = ((i >> 1) ^ i);
        cout << code.to_string().substr(16-N, N) << '\n';
    }

    return 0;
}