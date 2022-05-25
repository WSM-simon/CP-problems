#include <bits/stdc++.h>
#define ll long long
#define ar3 array<long long, 3>
#define f first
#define s second

using namespace std;

const int MxN = 43;
const int MxM = 1e5 + 3;

int N, ans[MxN];
pair<ll, ll> target;
vector<pair<ll, ll>> inst1, inst2;
vector<pair<ll, ll>> mix1, mix2;
map<pair<ll,ll>, vector<ll>> steps_count1, steps_count2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> target.f >> target.s;
    for (int i = 0; i < N; ++i)
    {
        pair<ll, ll> tem;
        cin >> tem.f >> tem.s;
        if (i % 2)
            inst1.push_back(tem);
        else
            inst2.push_back(tem);
    }
    int size_inst1 = (int)inst1.size(), size_inst2 = (int)inst2.size();

    // find the mix1
    for (int i = 0; i < (1 << size_inst1); ++i)
    {
        int cnt = 0;
        pair<ll, ll> co = {0, 0};
        for (int j = 0; j < size_inst1; ++j)
            if ((1 << j) & i)
                co.f += inst1[j].f, co.s += inst1[j].s, cnt++;
        mix1.push_back(co);
        steps_count1[co].push_back(cnt);
    }

    // find the mix2
    for (int i = 0; i < (1 << size_inst2); ++i)
    {
        int cnt = 0;
        pair<ll, ll> co = {0, 0};
        for (int j = 0; j < size_inst2; ++j)
            if ((1 << j) & i)
                co.f += inst2[j].f, co.s += inst2[j].s, cnt++;
        mix2.push_back(co);
        steps_count2[co].push_back(cnt);
    }

    int size_mix1 = (int)mix1.size(), size_mix2 = (int)mix2.size();
    // do binary search, search the (target - mix1[i]) in mix2
    // sort(mix2.begin(), mix2.end());
    for (int i=0; i<size_mix1; ++i)
    {
        pair<ll,ll> obj = {target.f - mix1[i].f, target.s-mix1[i].s};
        if (steps_count2.find(obj) != steps_count2.end())
            for (int i:steps_count1[mix1[i]])
                for (int j:steps_count2[obj])
                    ans[i+j]++;
    }

    for (int i=1; i<=N; ++i)
        cout << ans[i] << '\n';
    return 0;
}
