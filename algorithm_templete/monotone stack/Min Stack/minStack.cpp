// https://leetcode.cn/problems/min-stack/
// Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <bits/stdc++.h>
#define ll long long

using namespace std;

class MinStack {
    stack<int> stk, helper;

public:
    MinStack() {
        helper.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        if (!helper.empty() && helper.top() >= val)
            helper.push(val);
    }

    void pop() {
        if (stk.empty()) return;
        if (!helper.empty() && helper.top() == stk.top())
            helper.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return helper.top();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinStack stk;
    return 0;
}
