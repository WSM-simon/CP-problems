#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

bool check(string s1, string s2)
{
    list<char> str(s1.begin(), s1.end());
    list<char> str2(s2.begin(), s2.end());
    auto it = str.begin(), it2 = ++str.begin();
    while (it != str.end() && it2 != str.end() && !str.empty() && !str2.empty())
    {
        if (str.front() == str2.front())
        {
            str.pop_front();
            str2.pop_front();
            it = str.begin();
            it2 = ++str.begin();
            continue;
        }
        if (*it == *it2 && *it != 'z')
        {
            str.erase(it2);
            *it = *it + 1;
            it = --str.begin();
            it2 = str.begin();
        }
        it++, it2++;
    }
    if (str.front() == str2.front())
    {
        str.pop_front();
        str2.pop_front();
        it = str.begin();
        it2 = ++str.begin();
    }
    if (str2.size() == 0 && str.size() == 0)
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() >= s2.size() && check(s1, s2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
