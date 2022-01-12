#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_set<int> numSet;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        numSet.insert(i);
    for (int i = 0; i < n-1; i++)
    {
        int tem;
        cin >> tem;
        numSet.erase(tem);
    }
    for (int i : numSet)
        cout << i << '\n';

    return 0;
}