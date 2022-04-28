#include <bits/stdc++.h>
#define ll long long

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp;
    for (int i:nums)
    {
        auto it = lower_bound(dp.begin(),dp.end(),i);
        if (it == dp.end())
            dp.push_back(i);
        else
            *it = i;
    }
    return (int)dp.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(v);
    return 0;
}
