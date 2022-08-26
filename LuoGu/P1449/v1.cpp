#include <bits/stdc++.h>
#define ll long long

using namespace std;

stack<int> stk;
char c = ' ';
int t = 0, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (c != '@') {
        c = getchar();
        switch (c) {
        case '+':
            x = stk.top(), stk.pop();
            y = stk.top(), stk.pop();
            stk.push(y + x);
            break;
        case '-':
            x = stk.top(), stk.pop();
            y = stk.top(), stk.pop();
            stk.push(y - x);
            break;
        case '*':
            x = stk.top(), stk.pop();
            y = stk.top(), stk.pop();
            stk.push(y * x);
            break;
        case '/':
            x = stk.top(), stk.pop();
            y = stk.top(), stk.pop();
            stk.push(y / x);
            break;
        case '.':
            stk.push(t), t = 0;
            break;
        default:
            t = t * 10 + c - '0';
            break;
        }
    }
    cout << stk.top();
    return 0;
}