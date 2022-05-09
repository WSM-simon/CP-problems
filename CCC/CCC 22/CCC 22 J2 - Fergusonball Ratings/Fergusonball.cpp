#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, cnt=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int t1, t2;
        cin >>t1 >> t2;
        int score = t1*5-t2*3;
        if (score > 40)
            cnt++;
    }
    cout << cnt;
    if (cnt == N)
        cout << '+';
    cout << '\n';
    return 0;
}
