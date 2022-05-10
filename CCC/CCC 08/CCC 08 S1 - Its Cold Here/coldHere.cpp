#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

set<pair<int, string>> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int tem;
    while (cin >> s >> tem)
        st.insert(make_pair(tem, s));
    cout << st.begin()->second;
    
    return 0;
}
