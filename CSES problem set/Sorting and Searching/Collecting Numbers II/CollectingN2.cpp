#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200001;
int pos[Max];
int val[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++)
    {
        int tem;
        cin >> tem;
        pos[tem] = i;
        val[i] = tem;
    }

    int inver = 1;
    for (int i = 1; i < n; i++)
        inver+=(pos[i] > pos[i+1]);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        set<pii> update;
        if (val[a] + 1 <= n)
            update.insert({val[a], val[a] + 1});
        if (val[a] - 1 >= 1)
            update.insert({val[a] - 1, val[a]});
        if (val[b] + 1 <= n)
            update.insert({val[b], val[b] + 1});
        if (val[b] - 1 >= 1)
            update.insert({val[b] - 1, val[b]});

        for (pii p : update)
            inver -= (pos[p.first] > pos[p.second]);

        swap(val[a], val[b]);
        swap(pos[val[a]], pos[val[b]]);

        for (pii p : update)
            inver += (pos[p.first] > pos[p.second]);

        cout << inver << '\n';
    }

    return 0;
}