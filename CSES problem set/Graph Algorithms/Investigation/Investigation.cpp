#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
#define f first
#define s second

using namespace std;

const int Max = 1e5 + 3;
const int MOD = 1e9 + 7;

int N, M;
ll dis[Max], minF[Max], maxF[Max], route[Max];
vector<pli> adj[Max];
// [node1] = {dist, node2}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // maxF & route are already 0;
    fill(dis, dis + Max, LLONG_MAX);
    fill(minF, minF + Max, LLONG_MAX);

    minF[1] = 0;
    route[1] = 1;
    dis[1] = 0;

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int t1, t2;
        ll t3;

        cin >> t1 >> t2 >> t3;
        adj[t1].push_back({t3, t2});
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll d = pq.top().f;
        int n = pq.top().s;
        pq.pop();

        if (dis[n] != d)
            continue;

        for (pli p : adj[n])
        {
            ll pd = p.f;
            int pn = p.s;
             
            if (dis[pn] < d + pd)
                continue;

            else if (dis[pn] > d + pd)
            {
                minF[pn] = minF[n]+1, maxF[pn] = maxF[n]+1;
                dis[pn] = d + pd;
                route[pn] = route[n];
                pq.push({dis[pn], pn});
            }

            else
            {
                route[pn] = (route[pn] + route[n]) % MOD;
                minF[pn] = min(minF[pn], minF[n] + 1);
                maxF[pn] = max(maxF[pn], maxF[n] + 1);
            }
        }
    }

    cout << dis[N] << ' ' << route[N] << ' ' << minF[N] << ' ' << maxF[N];
    return 0;
}