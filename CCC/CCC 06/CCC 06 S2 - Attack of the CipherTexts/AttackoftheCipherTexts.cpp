#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<char, char> mp;
    string t1, t2, code;
    getline(cin, t1);
    getline(cin, t2);
    getline(cin, code);
    for (int i = 0; i < t1.size(); ++i)
        mp.insert(make_pair(t2[i], t1[i]));

    for (char c : code)
    {
        if (mp.find(c) != mp.end())
            cout << mp[c];
        else
            cout << '.';
    }
    return 0;
}