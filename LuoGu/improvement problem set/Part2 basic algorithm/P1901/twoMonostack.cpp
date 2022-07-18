#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, ans1[MxN], ans2[MxN];
pii arr[MxN];
stack<int> stk1, stk2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i].f >> arr[i].s;
    // right
    for (int i = N - 1; i >= 0; --i) {
        while (!stk1.empty() && arr[stk1.top()].f < arr[i].f)
            stk1.pop();
        if (!stk1.empty())
            ans1[stk1.top()] += arr[i].s;
        stk1.push(i);
    }
    // left
    for (int i = 0; i < N; ++i) {
        while (!stk2.empty() && arr[stk2.top()].f < arr[i].f)
            stk2.pop();
        if (!stk2.empty())
            ans2[stk2.top()] += arr[i].s;
        stk2.push(i);
    }
    // merge
    for (int i = 0; i < N; ++i)
        ans1[i] += ans2[i];
    cout << *max_element(ans1, ans1 + N) << ' ';
    return 0;
}
