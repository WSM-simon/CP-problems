#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
multiset<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int tem;
        cin >> tem;
        s.insert(tem);
    }
    vector<int> ans;
    while (!s.empty())
    {
        // push 2 numbers into ans at the same time
        // the first one is t1 = s.begin()
        // find the second which is M-t1
        // if M-t1 is given, just use it
        // otherwise use binarys earch
        int t1 = *s.begin();
        s.erase(s.begin());
        int t2 = M - t1;
        ans.push_back(t1);

        // if t1 is in set s
        auto pos1 = s.find(t2);
        // cpp is fk weird, if t1 is not in set s, the function "find" will return an iterator which points to the end of set s
        if (pos1 != s.end())
        {
            ans.push_back(t2);
            s.erase(pos1);
        }
        else
        {
            // else use binary search find the upperbound
            auto pos2 = s.upper_bound(t2);
            // samething here
            if (pos2 == s.end())
                break;
            ans.push_back(*pos2);
            s.erase(pos2);
        }
    }
    if (ans.size() == N)
    {
        for (int v : ans)
            cout << v << ' ';
        cout << '\n';
    }
    else
        cout << "-1\n";
    return 0;
}
