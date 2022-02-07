#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 30000000;
const int inf = 0x3f3f3f3f;

int N;
ll memo[Max];

// function solve is solving the answer for subtree which had weight n.
ll solve(int n)
{
    if (n <= Max && memo[n])
        return memo[n];
    // k is the quanlity of each branch of sub-trees
    // nex is the quanlity of each branch of sub-trees with weight q
    ll ans = 0;
    for (int k = n, nex, q; k > 1; k = nex)
    {
        // k-nex is how many i-weight sub-tree there are.
        // q is the weight of branches
        q = n / k, nex = n / (q + 1);
        ans += (k - nex) * solve(q);
    }
    if (n <= Max)
        memo[n] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    memo[1] = 1;
    cout << solve(N) << '\n';
    return 0;
}
