#include <bits/stdc++.h>
#define ll long long
#define inf 1e18

using namespace std;

const int MxN = 45;

ll N, M, cnt = 0;
vector<ll> arr1, arr2, v1, v2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int tem;
        cin >> tem;
        if (tem <= M)
        {
            if (i % 2)
                arr1.push_back(tem);
            else
                arr2.push_back(tem);
        }
    }

    int size_arr1 = (int)arr1.size(), size_arr2 = (int)arr2.size();
    for (int i = 0; i < (1 << size_arr1); ++i)
    {
        ll sum = 0;
        for (int j = 0; j < size_arr1; ++j)
        {
            if ((i >> j) & 1)
                sum += arr1[j];
        }
        v1.push_back(sum);
    }
    for (int i = 0; i < (1 << size_arr2); ++i)
    {
        ll sum = 0;
        for (int j = 0; j < size_arr2; ++j)
        {
            if ((i >> j) & 1)
                sum += arr2[j];
        }
        v2.push_back(sum);
    }
    // two pointers
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    ll pt = 0, pre = inf, cnt2 = inf;
    int size_v2 = (int)v2.size();
    for (auto r : v1)
    {
        ll diff = M - r;
        if (diff != pre)
        {
            pre = diff, cnt2 = 0;
            for (; pt < size_v2 && v2[pt] > diff; ++pt);
            for (; pt < size_v2 && v2[pt] == diff; ++pt)
                cnt2++;
        }
        cnt += cnt2;
    }
    cout << cnt << "\n";
    return 0;
}