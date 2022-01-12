#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

vector<vector<int>> adj(8);
int inDeg[8] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    adj[1].push_back(7);
    inDeg[7]++;
    adj[1].push_back(4);
    inDeg[4]++;
    adj[2].push_back(1);
    inDeg[1]++;
    adj[3].push_back(5);
    inDeg[5]++;
    adj[3].push_back(4);
    inDeg[4]++;

    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        adj[a].push_back(b);
        inDeg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> output;

    for (int i = 1; i <= 7; i++)
        if (inDeg[i] == 0)
            pq.push(i);

    while (!pq.empty())
    {
        int node = pq.top();
        output.push(node);
        pq.pop();

        for (int i : adj[node])
        {
            inDeg[i]--;
            if (inDeg[i] == 0)
                pq.push(i);
        }
    }

    if (output.size() == 7)
        while (!output.empty())
        {
            cout << output.front() << ' ';
            output.pop();
        }
    else
        cout << "Cannot complete these tasks. Going to bed.";

    return 0;
}