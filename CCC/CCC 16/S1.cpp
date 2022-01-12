#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    map<char, int> mp1, mp2;
    cin >> s1 >> s2;
    for (int c = 'a'; c <= 'z'; ++c)
    {
        mp1.insert(make_pair(c, count(s1.begin(), s1.end(), c)));
        mp2.insert(make_pair(c, count(s2.begin(), s2.end(), c)));
    }
    mp2.insert(make_pair('*', count(s2.begin(), s2.end(), '*')));
    for (int c = 'a'; c <= 'z'; ++c)
    {
        if (mp1[c] != mp2[c])
        {
            if ((mp2[c] < mp1[c]) && mp2['*'] >= (mp1[c] - mp2[c]))
            {
                mp2['*'] -= (mp1[c] - mp2[c]);
                continue;
            }
            cout << 'N';
            return 0;
        }
    }
    cout << 'A';
    return 0;
}