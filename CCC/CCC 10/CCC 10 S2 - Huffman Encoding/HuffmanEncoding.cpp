#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;

int N;

unordered_map<size_t, char> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    hash<string> hasher;
    for (int i = 0; i < N; ++i)
    {
        char c;
        string s;
        cin >> c >> s;
        size_t h = hasher(s);
        mp.insert(make_pair(h, c));
    }

    string code;
    cin >> code;
    int p1 = 0;
    while (p1 < (int)code.size())
    {
        string tem = "";
        for (int k = 0; p1 + k < (int)code.size(); ++k)
        {
            tem.append(1, code[p1 + k]);
            size_t h = hasher(tem);
            if (mp.find(h) != mp.end())
            {
                cout << mp[h];
                p1 += k + 1;
                break;
            }
        }
    }
    return 0;
}
