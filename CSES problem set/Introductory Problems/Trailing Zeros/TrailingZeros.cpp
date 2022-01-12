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

    cin >> N;
    int cnt = 0;
    for (int i = 5; i <= N; i *= 5)
    {
        cnt += N / i;
    }

    cout << cnt;
    return 0;
}