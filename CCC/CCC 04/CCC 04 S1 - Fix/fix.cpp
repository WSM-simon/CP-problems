#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N;

bool check(string s1, string s2)
{
    if (s1.size() < s2.size())
        swap(s1, s2);
    bool fixfree = 0;
    for (int i = 0; i < (int)s2.size(); ++i)
    {
        if (s1[i] != s2[i])
        {
            fixfree = 1;
            break;
        }
    }
    if (!fixfree)
        return 0;

    fixfree = 0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < (int)s2.size(); ++i)
    {
        if (s1[i] != s2[i])
        {
            fixfree = 1;
            break;
        }
    }
    if (!fixfree)
        return 0;
    return 1;
}

void solve()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (!check(s1, s2) || !check(s2, s3) || !check(s1, s3))
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--)
        solve();
    return 0;
}
