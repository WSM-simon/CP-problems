#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    vector<string> permutation={s};
    while (next_permutation(s.begin(), s.end()))
        permutation.push_back(s);

    cout << permutation.size() << '\n';
    for (string ss:permutation)
        cout << ss << '\n';
        
    return 0;
}