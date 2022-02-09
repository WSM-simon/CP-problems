#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string lay, needle;
    cin >> lay >> needle;
    for (int i = 0; i < (int)needle.size(); ++i)
    {
        needle.append(1, needle[0]);
        needle.erase(needle.begin());
        if (lay.find(needle) != string::npos)
        {
            cout << "yes\n";
            return 0;
        }
    }
    cout << "no\n";
    return 0;
}
