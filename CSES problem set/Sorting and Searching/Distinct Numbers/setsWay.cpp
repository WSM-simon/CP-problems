#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<int> st;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int tem;
        cin >> tem;
        st.insert(tem);
    }
    
    cout <<st.size();
    return 0;
}