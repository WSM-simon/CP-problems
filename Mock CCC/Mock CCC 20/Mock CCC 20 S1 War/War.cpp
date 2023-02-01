#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N, c1[1003], c2[1003], cnt = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> c1[i];

    for (int i = 0; i < N; ++i)
        cin >> c2[i];

    for (int i = 0; i < N - 1; ++i)
    {
        if (c1[i] == c2[i] && c1[i + 1] != c2[i + 1])
            ++cnt;
    }
    if (c1[N - 1] == c2[N - 1])
        ++cnt;

    cout << cnt;
    return 0;
}