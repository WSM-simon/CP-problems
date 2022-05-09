#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M, count1[26], count2[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (char c : s1)
        if (c != ' ')
            count1[c - 'A']++;
    for (char c : s2)
        if (c != ' ')
            count2[c - 'A']++;
    for (int i = 0; i < 26; ++i)
        if (count1[i] != count2[i])
        {
            cout << "Is not an anagram.\n";
            return 0;
        }
    cout << "Is an anagram.\n";
    return 0;
}
