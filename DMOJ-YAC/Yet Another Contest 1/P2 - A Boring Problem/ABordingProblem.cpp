#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

int N;
ll badpath = 0;
bool col[MxN];
struct node;
node path[MxN];

struct node {
    vector<int> white, black;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        char c;
        cin >> c;
        if (c == 'B') col[i] = 1;
    }
    for (int i = 1; i <= N - 1; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        if (col[t1])
            path[t2].black.push_back(t1);
        else
            path[t2].white.push_back(t1);
        if (col[t2])
            path[t1].black.push_back(t2);
        else
            path[t1].white.push_back(t2);
    }
    for (int i = 1; i <= N; ++i) {
        if (col[i]) {
            badpath+=path[i].black.size() * path[i].white.size() + 
        }
    }

    return 0;
}
