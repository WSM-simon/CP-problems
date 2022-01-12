#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int const Max = 2e2 + 3;
int const MaxD = 20;

int N, M;
ll arr[Max][MaxD];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> arr[i][0];

    for (int i = 1; i < MaxD; ++i)
        for (int j = 0; j + (1 << i) - 1 < N; ++j)
            arr[j][i] = min(arr[j][i - 1], arr[j + (1 << (i - 1))][i - 1]);

    return 0;
}