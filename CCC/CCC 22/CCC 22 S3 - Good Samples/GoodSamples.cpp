#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int MxN = 1e5 + 3;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll N, M, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    if (M > N)
        M = N;

    K -= N;
    if (K < 0 || K > M * (M - 1) / 2 + (N - M) * (M - 1))
    {
        cout << "-1\n";
        return 0;
    }
    vector<ll> ans;
    // here is M-1 not M+1
    // because K already minus N
    if (K <= M * (M - 1) / 2)
    {
        ll last = 0;
        while (K - last >= 0)
        {
            K = K - last;
            ans.push_back(last + 1);
            last++;
        }
        ll p = *(ans.end() - 1 - K);
        while ((int)ans.size() < N)
        {
            ans.push_back(p);
        }
        K = 0;
    }
    else
    {
        for (int i = 1; i <= M; ++i)
            ans.push_back(i);
        K -= M * (M - 1) / 2;
        while (K > M * (M - 1))
        {
            for (int i = 1; i <= M; ++i)
                ans.push_back(i);
            K -= M * (M - 1);
        }
        if (K > M - 1)
        {
            ll last = 0;
            while (K > M - 1)
            {
                K -= M - 1;
                ans.push_back(last + 1);
                last++;
            }
        }
        ll p = *(ans.end() - 1 - K);
        while ((int)ans.size() < N)
        {
            ans.push_back(p);
        }
        K = 0;
    }
    for (int i = 0; i < N; ++i)
        cout << ans[i] << "\n "[i == N - 1 ? 0 : 1];
    return 0;
}
