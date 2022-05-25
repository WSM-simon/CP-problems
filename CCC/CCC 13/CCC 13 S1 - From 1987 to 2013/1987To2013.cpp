#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

bool is_distinct(int x)
{
    string s=to_string(x);
    sort(s.begin(), s.end());
    auto it = unique(s.begin(), s.end());
    return it == s.end();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=N; i<20000; ++i)
    {
        if (is_distinct(i))
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
