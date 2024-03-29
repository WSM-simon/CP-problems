#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 3e5 + 3;

class my_stack {
    // use the first item in stk to represent the num of total items in stack
    // very cool
private:
    ll stk[MxN] = {0};

public:
    void push(int val) {
        stk[++*stk] = val;
    }
    ll top() {
        return stk[*stk];
    }
    void pop() {
        if (*stk) --*stk;
    }
    void clear() {
        *stk = 0;
    }
    bool empty() {
        return *stk == 0;
    }
};

ll N, arr[MxN], cnt = 0;
my_stack stk;

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