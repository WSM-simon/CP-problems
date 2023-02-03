#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;
const ll INF = 1e18 + 7;

ll N, ans;
vector<ll> pos_light_off, graph;
map<ll, ll> dis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        int h = c - '0';
        graph.push_back(h);
        if (h == 0) pos_light_off.push_back(i);
    }
    for (int i : pos_light_off) {
        dis[i] = INF;
    }

    int pos_l = -1;
    for (int i = 0; i < N; ++i) {
        int x = graph[i];
        if (x == 0 && pos_l != -1) {
            dis[i] = min((ll)i - pos_l, dis[i]);
        } else if (x == 1) {
            pos_l = i;
        }
    }

    reverse(graph.begin(), graph.end());
    pos_l = -1;
    for (int i = 0; i < N; ++i) {
        int x = graph[i];
        if (x == 0 && pos_l != -1) {
            dis[N - i - 1] = min((ll)i - pos_l, dis[N - i - 1]);
        } else if (x == 1) {
            pos_l = i;
        }
    }
    ll ans = 0;
    for (int i : pos_light_off) {
        ans += dis[i];
    }
    cout << ans << '\n';
    return 0;
}
