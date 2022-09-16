#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct symbol {
    int val;
    bool is_digit;
};

list<symbol> RPN() {
    stack<symbol> stk;
    list<symbol> res;
    char c;
    while (cin >> c) {
        symbol s = {c, 0};
        if (isdigit(c)) {
            s.val -= '0';
            s.is_digit = 1;
            res.emplace_back(s);
            continue;
        }
        if (s.val == '+' || s.val == '-') {
            while (!stk.empty()) {
                res.emplace_back(stk.top());
                stk.pop();
            }
            stk.push(s);
        } else if (s.val == '*' || s.val == '/') {
            if (!stk.empty()) {
                while (!stk.empty() && (stk.top().val == '^' || stk.top().val == '*' || stk.top().val == '/')) {
                    res.emplace_back(stk.top());
                    stk.pop();
                }
            }
            stk.push(s);
        } else if (s.val == '^') {
            stk.push(s);
        } else if (s.val == '(') {
            auto r = RPN();
            res.insert(res.end(), r.begin(), r.end());
        } else if (s.val == ')') {
            while (!stk.empty()) {
                res.emplace_back(stk.top());
                stk.pop();
            }
            return res;
        }
    }
    while (!stk.empty()) {
        res.emplace_back(stk.top());
        stk.pop();
    }
    return res;
}

void print(list<symbol> equ) {
    for (symbol s : equ)
    {
        if (s.is_digit)
            cout << s.val << ' ';
        else
            cout << char(s.val) << ' ';
    }
    cout << '\n';
}

void print_steps(list<symbol> equ) {
    print(equ);
    while (equ.size() > 1) {
        auto ptr = equ.begin();
        for (; ptr != equ.end() && ptr->is_digit; ptr++);
        auto a = prev(ptr,2), b = prev(ptr, 1);
        switch (ptr->val) {
        case '+': a->val += b->val; break;
        case '-': a->val -= b->val; break;
        case '*': a->val *= b->val; break;
        case '/': a->val /= b->val; break;
        case '^': a->val = pow(a->val, b->val); break;
        }
        equ.erase(b), equ.erase(ptr);
        print(equ);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    print_steps(RPN());
    return 0;
}