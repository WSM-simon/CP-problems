#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l = 0;
    char c;
    while (c != '@') {
        c = getchar();
        if (c == '(')
            l++;
        else if (c == ')') {
            if (--l < 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (l > 0)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}