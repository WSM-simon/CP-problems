#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
map<char, int> timesPress{
    {'a', 1},
    {'b', 2},
    {'c', 3},
    {'d', 1},
    {'e', 2},
    {'f', 3},
    {'g', 1},
    {'h', 2},
    {'i', 3},
    {'j', 1},
    {'k', 2},
    {'l', 3},
    {'m', 1},
    {'n', 2},
    {'o', 3},
    {'p', 1},
    {'q', 2},
    {'r', 3},
    {'s', 4},
    {'t', 1},
    {'u', 2},
    {'v', 3},
    {'w', 1},
    {'x', 2},
    {'y', 3},
    {'z', 4},
};

map<char, int> buttonOfLetter{
    {'a', 2},
    {'b', 2},
    {'c', 2},
    {'d', 3},
    {'e', 3},
    {'f', 3},
    {'g', 4},
    {'h', 4},
    {'i', 4},
    {'j', 5},
    {'k', 5},
    {'l', 5},
    {'m', 6},
    {'n', 6},
    {'o', 6},
    {'p', 7},
    {'q', 7},
    {'r', 7},
    {'s', 7},
    {'t', 8},
    {'u', 8},
    {'v', 8},
    {'w', 9},
    {'x', 9},
    {'y', 9},
    {'z', 9},
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s)
    {
        if (s == "halt")
            break;
        int cnt = 0, pre = 0;
        for (char c : s)
        {
            int butn = buttonOfLetter[c];
            int pres = timesPress[c];
            if (butn == pre)
                cnt += 2;
            pre = butn;
            cnt += pres;
        }
        cout << cnt << '\n';
    }
    return 0;
}
