#include <bits/stdc++.h>
#define ADD 43 // 加法
#define SUB 45 // 减法
#define MUL 42 // 乘法
#define DIV 47 // 除法
#define POW 94 // 乘方
#define LFT 40 // 左括号
#define RHT 41 // 右括号
using namespace std;
int priority(int op) { // 返回运算符优先级
    switch (op) {
    case ADD:
    case SUB: return 1; // 加减法优先级最低

    case MUL:
    case DIV: return 2; // 乘除法次之

    case POW: return 3;  // 乘方最高
    case LFT: return -1; // 保证左括号不会在第 34 行处被弹出
    default: assert(0);  // 不可能执行
    }
    assert(0);
    return 0; // 不可能执行
}
vector<pair<int, bool>> transform(string exp) { // 中缀转后缀
    exp = "(" + exp + ")";                      // 两边加括号
    vector<pair<int, bool>> res;                // 后缀表达式（若 second 为 false，则 first 为数字；否则 first 为某个运算符的 ASCII 码）
    stack<int> stk;                             // 运算符栈
    for (auto i : exp) {                        // 枚举每个字符
        if (isdigit(i))
            res.emplace_back(i - '0', false); // 数字直接放到 res 里
        else if (i == LFT)
            stk.push(i);               // 左括号直接入栈
        else if (i == RHT) {           // 右括号
            while (stk.top() != LFT) { // 把当前栈里左括号之前的运算符弹出并放到 res 里
                res.emplace_back(stk.top(), true);
                stk.pop();
            }
            stk.pop();                                   // 弹出左括号
        } else {                                         // 运算符
            while (priority(i) <= priority(stk.top())) { // 把栈里大于当前优先级的运算符弹出并放到 res 里
                if (i == POW && stk.top() == POW) break; // 保证乘方运算是右结合的
                res.emplace_back(stk.top(), true);
                stk.pop();
            }
            stk.push(i); // 当前运算符入栈
        }
    }
    return res;
}
void print(vector<pair<int, bool>> exp) { // 输出表达式
    for (auto [x, tp] : exp) {
        if (tp)
            cout << char(x) << " ";
        else
            cout << x << " ";
    }
    cout << endl;
}
void calc_and_print(vector<pair<int, bool>> exp) { // 边计算边输出
    while (exp.size() > 1) {                       // 直到只剩一个最终答案
        print(exp);                                // 输出
        int ptr = 0;
        for (int i = 0; i < exp.size(); i++) {
            if (exp[i].second) {
                ptr = i;
                break;
            } // 找到第一个运算符
        }
        switch (exp[ptr].first) { // 计算
        case ADD: exp[ptr - 2].first += exp[ptr - 1].first; break;
        case SUB: exp[ptr - 2].first -= exp[ptr - 1].first; break;
        case MUL: exp[ptr - 2].first *= exp[ptr - 1].first; break;
        case DIV: exp[ptr - 2].first /= exp[ptr - 1].first; break;
        case POW: exp[ptr - 2].first = pow(exp[ptr - 2].first, exp[ptr - 1].first); break;
        default: assert(0);
        }
        exp.erase(exp.begin() + ptr);
        exp.erase(exp.begin() + ptr - 1);
    }
    printf("%d\n", exp[0].first);
}
int main() {
    string e;
    cin >> e;
    calc_and_print(transform(e));
    return 0; // 完美的结尾！撒花！
}