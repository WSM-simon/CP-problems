#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int Max = 1e2 + 3;
const int inf = 0x3f3f3f3f;

int N, M, real_N = 0, order[Max], prefix[Max], ans_in_range[Max];
bool pos[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int p;
        cin >> p;
        if (!pos[p])
        {
            real_N++;
            pos[p] = 1;
            order[i] = p;
        }
    }
    // the order of where the points are.
    sort(order, order + real_N);
    if (pos[0])
        prefix[0] = 1;
    // prefix used to find the number of points in range(a,b)
    for (int i = 1; i < M; ++i)
        prefix[i] = prefix[i - 1] + pos[i];
    for (int i = 0; i < real_N - 1; ++i)
    {
        if (order[i] + M / 2 > order[i + 1])
        {
            int p1 = (M / 2 + order[i + 1] - 1) % M;
            int p2 = (M / 2 + order[i] + 1) % M;
            ans_in_range[i] = max(0, prefix[p2 - 1] - prefix[p1 - 1]);
        }
    }
    // special case for the last P
    if (order[real_N] - M / 2 <= order[1])
    {
        int p1 = (M / 2 + order[1] - 1) % M;
        int p2 = (M / 2 + order[real_N] + 1) % M;
        ans_in_range[real_N-1] = max(0, prefix[p2 - 1] - prefix[p1 - 1]);
    }
    for (int i = 0; i < M; ++i)
        cout << prefix[i] << ' ';
    cout << '\n';
    for (int i = 0; i < real_N; ++i)
        cout << ans_in_range[i] << '\n';
    return 0;
}
