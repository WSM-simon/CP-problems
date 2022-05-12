#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i += 2)
    {
        if (i == s.size() - 2)
        {
            ans += (s[i]-'0')*mp[s[i+1]];
            break;
        }
        // adding
        if (mp[s[i+1]] >= mp[s[i+3]])
            ans+=(s[i]-'0')*mp[s[i+1]];
        // minus
        else 
            ans-=(s[i]-'0')*mp[s[i+1]];
    }
    cout << ans << '\n';
    return 0;
}