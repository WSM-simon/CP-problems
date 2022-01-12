#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    unsigned ll a=1;
    for (ll i = 0; i < N; i++){
        a=(a*2)%MOD; 
    }
    
    cout << a;

    return 0;
}