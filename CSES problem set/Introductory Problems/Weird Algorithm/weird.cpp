#include <bits/stdc++.h>
using namespace std;

long long N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cout << N << ' ';
    while(N!=1){
        if ((N&1)==1)
            N=N*3+1;
        else
            N/=2;
        cout << N << ' ';
    }
    return 0;
}