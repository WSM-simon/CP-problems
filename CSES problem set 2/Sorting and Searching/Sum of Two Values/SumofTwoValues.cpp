#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
pair<int, int> arr[MxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        arr[i] = {t, i + 1};
    }
    sort(arr, arr + N);
    for (int i = 0, j = N - 1; i < N && j >= 0 && i != j; i++) {
        while (arr[i].f + arr[j].f > M && j > 0 && i != j - 1)
            j--;
        if (arr[i].f + arr[j].f == M) {
            cout << arr[i].s << ' ' << arr[j].s;
            exit(0);
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
