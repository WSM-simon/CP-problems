#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
vector<int> v, ans;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tem;
        cin >> tem;
        v.push_back(tem);
    }
    for (int i = N - 1; i >= 0; i--) {
        while (!stk.empty() && v[stk.top()] <= v[i])
            stk.pop();
        ans.push_back(stk.empty() ? 0 : stk.top()+1);
        stk.push(i);
    }
    for (int i = N - 1; i >= 0; --i)
        cout << ans[i] << ' ';
    return 0;
}
