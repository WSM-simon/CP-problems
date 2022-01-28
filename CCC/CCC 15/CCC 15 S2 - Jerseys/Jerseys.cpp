#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e6 + 3;

int N, M, arr[Max];

int convert(char c)
{
    if (c == 'S')
        return 1;
    if (c == 'M')
        return 2;
    if (c == 'L')
        return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        char tem;
        cin >> tem;
        arr[i] = convert(tem);
    }

    int cnt = 0;
    for (int i = 0; i < M; ++i)
    {
        char t1;
        int t2;
        cin >> t1 >> t2;
        if (arr[t2] >= convert(t1))
            cnt++, arr[t2] = -1;
    }
    cout << cnt;
    return 0;
}
