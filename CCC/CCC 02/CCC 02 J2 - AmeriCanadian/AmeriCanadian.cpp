#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'y'};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s)
    {
        bool is_Ameri = 0;
        if (s == "quit!")
            break;
        if (s.size() <= 4)
        {
            cout << s << '\n';
            continue;
        }
        auto it = s.end();
        it--;
        if (*it == 'r')
        {
            it--;
            if (*it == 'o')
            {
                it--;
                if (vowel.find(*it) == vowel.end())
                    is_Ameri = 1;
            }
        }
        if (is_Ameri)
            cout << s.substr(0, s.size() - 2) << "our\n";
        else
            cout << s << '\n';
    }
    return 0;
}
