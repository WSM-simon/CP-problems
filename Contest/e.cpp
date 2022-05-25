#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

bool check(string s1, string s2)
{
    for (char c : s2)
    {
        int now=0, goal = c - 'a' + 1;
        list<char> str;
        for (int i = 0; i < (int)s1.size() && now < goal; ++i)
        {
            str.push_back(s1[i]);
            now += s1[i] - 'a' + 1;
        }

        for (char c : str)
            cout << c;
        cout << '\n';

        if (now != goal)
            return 0;
    }
    return 1;
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
}