#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<string, char>> sk;
    char c, homeDirec;
    string s;
    cin >> homeDirec;
    while (cin >> s)
    {
        if (s == "SCHOOL")
        {
            while (!sk.empty())
            {
                pair<string, char> p = sk.top();
                sk.pop();
                cout << "Turn ";
                if (p.second == 'R')
                    cout << "LEFT onto ";
                if (p.second == 'L')
                    cout << "RIGHT onto ";
                cout << p.first << " street.\n";
            }
            cout << "Turn ";
            if (homeDirec == 'R')
                cout << "LEFT into your HOME.\n";
            if (homeDirec == 'L')
                cout << "RIGHT into your HOME.\n";

            return 0;
        }
        cin >> c;
        sk.push(make_pair(s, c));
    }
    return 0;
}
