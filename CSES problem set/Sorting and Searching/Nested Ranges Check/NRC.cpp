#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2 * 1e5 + 3;
int N;
pii order[];
set<pii> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        order[i] = pii(a, b);
        st.insert(pii(a, b));
    }


    return 0;
}