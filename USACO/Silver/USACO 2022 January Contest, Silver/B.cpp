#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
const int Max2 = 1e3 + 3;

int N, M, height[Max], lookup[Max2][Max2];

// Fills lookup heightay
// lookup[][] in bottom up manner.
void preprocess(int n)
{
    // Initialize M for the
    // intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = i;

    // Compute values from smaller
    // to bigger intervals
    for (int j = 1; (1 << j) <= n; j++)
    {
        // Compute minimum value for
        // all intervals with size
        // 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            // For height[2][10], we
            // compare height[lookup[0][3]]
            // and height[lookup[3][3]]
            if (height[lookup[i][j - 1]] > height[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

// Returns minimum of height[L..R]
int query(int L, int R)
{
    // For [2,10], j = 3
    int j = (int)log2(R - L + 1);

    // For [2,10], we compare height[lookup[0][3]] and
    // height[lookup[3][3]],
    if (height[lookup[L][j]] >= height[lookup[R - (1 << j) + 1][j]])
        return height[lookup[L][j]];

    else
        return height[lookup[R - (1 << j) + 1][j]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> height[i];
    preprocess(N);
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
        {
            if (i == j)
                continue;
            else if (j - i == 1)
                cnt += 1;
            else if (query(i + 1, j - 1) < min(i, j))
                cnt += j - i;
        }
    cout << cnt;
    return 0;
}
