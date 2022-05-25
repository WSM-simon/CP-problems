#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 45;

ll N, M, cnt = 0;
vector<ll> arr1, arr2, v1, v2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N / 2; ++i)
    {
        int tem;
        cin >> tem;
        if (tem <= M)
            arr1.push_back(tem);
    }
    for (int i = 0; i < (N / 2 + N % 2); ++i)
    {
        int tem;
        cin >> tem;
        if (tem <= M)
            arr2.push_back(tem);
    }
    for (int i = 0; i < (1 << (int)arr1.size()); ++i)
    {
        ll sum = 0;
        for (int j = 0; j < (int)arr1.size(); ++j)
        {
            if ((1 << j) & i)
                sum += arr1[j];
        }
        v1.push_back(sum);
    }
    for (int i = 0; i < (1 << (int)arr2.size()); ++i)
    {
        ll sum = 0;
        for (int j = 0; j < (int)arr2.size(); ++j)
        {
            if ((1 << j) & i)
                sum += arr2[j];
        }
        v2.push_back(sum);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < (int)v1.size(); ++i)
    {
        ll target = M - v1[i];
        // auto bounds = equal_range(v2.begin(), v2.end(), target);
        // cnt += bounds.second - bounds.first;
    }
    cout << cnt << "\n";
    return 0;
}