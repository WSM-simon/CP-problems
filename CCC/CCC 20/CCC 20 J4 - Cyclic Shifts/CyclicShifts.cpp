#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;

unordered_set<string> st;

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
        st.insert(needle);
    }
    string tem = lay.substr(0, needle.size());
    int p2 = needle.size() - 1;
    while (p2 < lay.size())
    {
        p2++;
        if (st.find(tem) != st.end())
        {
            cout << "yes\n";
            return 0;
        }
        tem.erase(tem.begin());
        tem.append(1, lay[p2]);
    }
    cout << "no\n";
    return 0;
}
