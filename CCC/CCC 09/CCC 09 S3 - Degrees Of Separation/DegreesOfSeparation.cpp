#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 53;
unordered_set<int> adj[Max] = {{}, {6}, {6}, {4, 5, 6, 15}, {3, 5, 6}, {3, 4, 6}, {1, 2, 3, 4, 5, 7}, {6, 8}, {7, 9}, {8, 10, 12}, {9, 11}, {10, 12}, {9, 11, 13}, {12, 14, 15}, {13}, {3, 13}, {17, 18}, {16, 18}, {16, 17}};

vector<int> output;

// void initAdd()
// {
//     adj[1] = {6};
//     adj[2] = {6};
//     adj[3] = {4, 5, 6, 15};
//     adj[4] = {3, 5, 6};
//     adj[5] = {3, 4, 6};
//     adj[6] = {1, 2, 3, 4, 5, 7};
//     adj[7] = {6, 8};
//     adj[8] = {7, 9};
//     adj[9] = {8, 10, 12};
//     adj[10] = {9, 11};
//     adj[11] = {10, 12};
//     adj[12] = {9, 11, 13};
//     adj[13] = {12, 14, 15};
//     adj[14] = {13};
//     adj[15] = {3, 13};
//     adj[16] = {18, 17};
//     adj[17] = {16, 18};
//     adj[18] = {16, 17};
// }

void i_(int a, int b)
{
    adj[a].insert(b);
    adj[b].insert(a);
}

void d_(int a, int b)
{
    adj[a].erase(b);
    adj[b].erase(a);
}

void n_(int a)
{
    output.push_back((int)adj[a].size());
}

void f_(int a)
{
    unordered_set<int> cntST;
    for (int v : adj[a])
        for (int n : adj[v])
            if (n != a && adj[a].find(n) == adj[n].end())
                cntST.insert(n);
    output.push_back((int)cntST.size());
}

void s_(int a, int b)
{
    bool vis[Max];
    int layer = 0;
    queue<int> q;
    vis[a] = 1;
    q.push(a);
    while (!q.empty())
    {
        ++layer;
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            int node = q.front();
            q.pop();
            for (int v : adj[node])
            {
                if (v == b)
                {
                    output.push_back(layer);
                    return;
                }
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    cout << "Not connected" << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // initAdd();
    char tem;
    // while (cin >> tem && tem != 'q')
    // {
    //     int a, b;
    //     switch (tem)
    //     {
    //     case 'i':
    //         cin >> a >> b;
    //         i_(a, b);
    //         break;
    //     case 'd':
    //         cin >> a >> b;
    //         d_(a, b);
    //         break;
    //     case 'n':
    //         cin >> a;
    //         n_(a);
    //         break;
    //     case 'f':
    //         cin >> a;
    //         f_(a);
    //         break;
    //     case 's':
    //         cin >> a >> b;
    //         s_(a, b);
    //     default:
    //         break;
    //     }
    // }
    s_(4, 2);
    for (int v : output)
        cout << v << '\n';
    return 0;
}