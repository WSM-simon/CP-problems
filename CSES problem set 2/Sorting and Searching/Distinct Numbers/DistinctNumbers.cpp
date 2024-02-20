#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;
ll arr[MxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0;i<N; ++i)
        cin >> arr[i];
    sort(arr, arr+N);
    int cnt = N;
    for (int i=0;i<N-1; ++i)
        if (arr[i] == arr[i+1])
            cnt--;
    cout << cnt;
    return 0;
}
