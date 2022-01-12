#include <bits/stdc++.h>
#define ll long long
#define arr array

using namespace std;

struct edge
{
    int a, b;
    ll w;
};

const int Max = 2503;
const ll INF = 1e18;
ll dis[Max];
int par[Max];
vector<edge> graph;

int N, M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        graph.push_back({t1, t2, t3});
    }

    fill(dis, dis + Max, INF);
    dis[1] = 0;
    int flag = 0;
    for (int i = 0; i < N; ++i)
    {
        flag = 0;
        for (size_t i = 0; i < graph.size(); ++i)
        {
            edge e = graph[i];
            if (dis[e.b] > dis[e.a] + e.w)
            {
                par[e.b] = e.a;
                dis[e.b] = dis[e.a] + e.w;
                flag = e.b;
            }
        }
        if (!flag)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < N; ++i)
        flag = par[flag];

    int fc = flag;
    stack<int> st;
    do
    {
        st.push(fc);
        fc = par[fc];
    } while (fc != flag);
    st.push(fc);

    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}