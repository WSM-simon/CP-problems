#include <bits/stdc++.h>
#define ll long long

using namespace std;


const int N = 1e3+3;

class my_stack{
    // use the first item in stk to represent the num of total items in stack
    // very cool
    private: 
        int stk[N] = {0};
    public: 
        void push(int val){
            stk[++*stk] = val;
        }
        int top(){
            return stk[*stk];
        }
        void pop(){
            if (*stk) --*stk;
        }
        void clear(){
            *stk = 0;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    my_stack sss;
    sss.push(123);
    sss.push(13);
    sss.push(99999);
    cout << sss.top() << '\n';
    sss.pop();
    cout << sss.top() << '\n';
    sss.pop();
    cout << sss.top() << '\n';
    sss.pop();

    return 0;
}
