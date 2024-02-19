#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200002;
bool vis[Max];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (vis[a - 1] == 0)
            cnt++;
        vis[a] = 1;
    }
    cout << cnt;
    return 0;
}