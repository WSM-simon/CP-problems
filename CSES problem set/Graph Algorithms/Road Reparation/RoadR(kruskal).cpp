#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 1e5+3;
int N, M;
vector<pair<int, pii>> path;
vector<ll> e;

int get(int x) {return (e[x]<0 ? x : e[x] = get(e[x])); }

bool unite(int x, int y)
{
    x = get(x), y = get(y);
    if (x == y)
        return 0;
    if (e[x] > e[y])
        swap(x, y);
    e[x]+=e[y], e[y]=x;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    e = vector<ll>(N+1, -1);
    for (int i=0; i<M; ++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        path.push_back({c, {a, b}});
    }
    sort(path.begin(), path.end());
    
    ll cnt=0, cost=0;
    for (auto v:path)
        if (unite(v.s.f, v.s.s))
            ++cnt, cost+=v.f;
    
    if (cnt == N-1)
        cout << cost;
    else
        cout << "IMPOSSIBLE";
    return 0;
}