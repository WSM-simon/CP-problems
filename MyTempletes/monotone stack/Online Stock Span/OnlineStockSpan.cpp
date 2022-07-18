#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

class StockSpanner {
    stack<int> stk;
    vector<int> v;
    int idx = 0;

public:
    StockSpanner() {
    }

    int next(int price) {
        v.push_back(price);
        while (!stk.empty() && v[stk.top()] <= price)
            stk.pop();
        int ans = 1;
        if (!stk.empty())
            ans = idx - stk.top() + 1;
        stk.push(idx);
        idx++;
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    StockSpanner S;
    int tem;
    while (cin >> tem)
        cout << S.next(tem) << ' ';
    return 0;
}