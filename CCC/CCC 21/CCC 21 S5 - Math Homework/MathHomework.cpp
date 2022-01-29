#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;

int N, M, arr[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    fill(arr, arr + Max, 1);
    for (int i = 1; i <= M; ++i)
    {
        int r1, r2, v;
        cin >> r1 >> r2 >> v;
        for (int j = r1; j <= r2; ++j)
        {
            if (arr[j] > v)
            {
                if (arr[j] % v == 0)
                    arr[j] *= v;
            }
            else if (v % arr[j] == 0)
                arr[j] *= v;
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << arr[i] << ' ';
    return 0;
}
