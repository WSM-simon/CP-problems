#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

void solve() {
    int L, num;
    string s;
    bool powerN = 0;
    cin >> L >> s;
    if (isdigit(s[2]))
        num = s[2]-'0';
    else 
        powerN = 1, num = s[4]-'0';
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--)
        solve();
    return 0;
}