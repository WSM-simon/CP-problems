#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

struct Comp
{
    bool operator()(const pair<string, int> p1, const pair<string, int> p2)
    {
        if (p1.s != p2.s)
            return p1.s > p2.s;
        else
            return p1.f < p2.f;
    }
};

int N;
set<pair<string, int>, Comp> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string s;
        int R, S, D;
        cin >> s;
        cin >> R >> S >> D;
        st.insert({s, 2 * R + 3 * S + D});
    }
    auto it = st.begin();
    for (int i = 0; i < min((size_t)2, st.size()); ++i)
        cout << it++->first << '\n';
    return 0;
}