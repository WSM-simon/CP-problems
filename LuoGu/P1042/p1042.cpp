#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
vector<pii> s11, s21;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    int w11 = 0, l11 = 0, w21 = 0, l21 = 0;
    while (cin >> c)
    {
        if (c == 'E')
        {
            s11.push_back({w11, l11});
            s21.push_back({w21, l21});
            break;
        }
        if (c == 'W')
            w11++, w21++;
        if (c == 'L')
            l11++, l21++;

        if (max(w11, l11) >= 11 && abs(w11 - l11) >= 2)
        {
            s11.push_back({w11, l11});
            w11 = 0, l11 = 0;
        }
        if (max(w21, l21) >= 21 && abs(w21 - l21) >= 2)
        {
            s21.push_back({w21, l21});
            w21 = 0, l21 = 0;
        }
    }
    for (pii p : s11)
        cout << p.first << ':' << p.second << '\n';
    cout << '\n';
    for (pii p : s21)
        cout << p.first << ':' << p.second << '\n';

    return 0;
}
