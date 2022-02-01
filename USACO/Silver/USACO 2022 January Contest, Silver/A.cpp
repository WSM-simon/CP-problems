#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

const int Max = 1;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        if (t1 == t2)
            cout << 0 << '\n';
        if (t1 < t2)
        {
            ll cnt = 0;
            while (t1 != t2)
            {
                if (t2 % 2 == 0)
                {
                    if (t2 / 2 < t1)
                        cnt += t2 - t1, t1 = t2;
                    else
                        t2 /= 2, cnt++;
                }
                else
                    t2--, cnt++;
            }
            cout << cnt << '\n';
        }
        if (t1 > t2)
        {
            vector<pll> seqt2;
            ll fincnt = 1e9 + 7;

            ll cntt2 = 0;
            seqt2.push_back({t2, cntt2});
            while (t2 != 1)
            {
                if (t2 % 2 == 0)
                {
                    t2 /= 2, cntt2++;
                    seqt2.push_back({t2, cntt2});
                }
                else
                {
                    t2--, cntt2++;
                    seqt2.push_back({t2, cntt2});
                }
            }
            sort(seqt2.begin(), seqt2.end());
            ll cntt1 = 0;
            while (t1 != 1)
            {
                if (t1 % 2 == 0)
                    t1 /= 2, cntt1++;
                else
                    t1++, cntt1++;
                auto low = lower_bound(seqt2.begin(), seqt2.end(), make_pair(t1, 0LL));
                if (low == seqt2.end())
                    continue;
                ll nlow = low->first;
                ll cnttt2 = low->second;
                if (nlow == t1)
                    fincnt = min(fincnt, cntt1 + cnttt2);
                else
                {
                    ll cnt = 0;
                    ll tt1 = t1, tt2 = nlow;
                    while (tt1 != tt2)
                    {
                        if (tt2 % 2 == 0)
                        {
                            if (tt2 / 2 < tt1)
                                cnt += tt2 - tt1, tt1 = tt2;
                            else
                                tt2 /= 2, cnt++;
                        }
                        else
                            tt2--, cnt++;
                    }
                    fincnt = min(fincnt, cntt1 + cnttt2 + cnt);
                }
            }
            cout << fincnt << '\n';
        }
    }
    return 0;
}
