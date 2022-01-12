#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
void solve()
{
    ll n;
    cin >> n;
    ll digit = 0;
 
    do
    {
        ll minus = 9 * pow(10, digit) * (digit+1);
 
        if (n <= minus)
        {
            ll rem = n % (digit + 1);
            ll quo = n / (digit + 1);

            ll num = pow(10, digit);
            num = num + quo - 1;
            
            if (rem != 0)
            {
                num++;
                string ansStr = to_string(num);
                cout << ansStr[rem - 1] << '\n';
            }
            else
            {
                string ansStr = to_string(num);
                cout << *(ansStr.end()-1) << '\n';
            }
            break;
        }
        else
            n -= minus;
 
    } while (++digit);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}