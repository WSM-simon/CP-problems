#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 25;
const int inf = 0x3f3f3f3f;

int K, ans = 1e9 + 7;

int bfs(bitset<Max> row)
{
    unordered_set<int> vis;
    queue<pair<bitset<Max>, int>> q;
    q.push({row,0});
    while (!q.empty())
    {
        bitset<Max> row2 = q.front().f;
        int cnt = q.front().s;
        q.pop();
        if (vis.find(row2.to_ulong()) != vis.end())
            continue;
        vis.insert(row2.to_ulong());
        if (row2.count() == 0)
            return cnt;
        for (int i=0; i<K; ++i)
        {
            bitset<Max> row3(row2);
            if (row3[i] == 0)
            {
                int cnt1 = 0, first1 = i;
                row3[i] = 1, cnt1++;
                // search forward
                for (int j = i+1; j<K && row3[j]; ++j)
                    cnt1++;
                // search backward
                for (int j=i-1; j>=0 && row3[j]; --j)
                    cnt1++, first1=j;
                if (cnt1>=4)
                    for (int j = first1; j<first1+cnt1; ++j)
                        row3[j] = 0;
                q.push({row3, cnt+1});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    bitset<Max> st;
    for (int i = 0; i < K; ++i)
    {
        int b;
        cin >> b;
        st[i] = b;
    }
    cout << bfs(st) << '\n';
    return 0;
}