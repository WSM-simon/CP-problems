#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 3e5 + 3;

ll N, arr[MxN], cnt = 0;
stack<ll> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = N - 1; i >= 0; --i) {
        while (!stk.empty() && arr[stk.top()] < arr[i])
            cnt += stk.top() - i + 1, stk.pop();
        if (!stk.empty())
            cnt += stk.top() - i + 1;
        stk.push(i);
    }
    cout << cnt << '\n';
    return 0;
}