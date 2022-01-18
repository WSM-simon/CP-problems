#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;

// d1 is the longest path, d2 is the second longest path, df is the fianl distance, which is the answer.
// child[a] = b means b belongs to the longest path of a.
int N, d1[Max], d2[Max], df[Max], child[Max];
vector<int> adj[Max];

void dfs1(int n, int p)
{
    for (int v : adj[n])
    {
        if (v == p)
            continue;
        dfs1(v, n);
        if (d1[n] < d1[v] + 1)
        {
            d2[n] = d1[n];
            d1[n] = d1[v] + 1;
            child[n] = v;
        }
        else if (d2[n] < d1[v] + 1)
            d2[n] = d1[v] + 1;
    }
}

void dfs2(int n, int p)
{
    for (int v : adj[n])
    {
        if (v == p)
            continue;
        // if v belongs to the longest path of n.
        if (child[n] == v)
        {
            // if node v itself has a shorter d1 than (d2+1) from its ancestor n.
            // do these:
            if (d1[v] < d2[n] + 1)
            {
                d2[v] = d1[v];
                d1[v] = d2[n] + 1;
                // v changes its child to n, cause n belongs to its new longeset path.
                child[v] = n;
            }
            else
                // because it is changing the d2 here, so we don't need to change the child.
                d2[v] = max(d2[v], d2[n] + 1);
        }
        else
        {
            d2[v] = d1[v];
            d1[v] = d1[n] + 1;
            // same idea as I just mentioned.
            child[v] = n;
        }
        dfs2(v, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs1(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= N; ++i)
        cout << d1[i] << ' ';

    return 0;
}