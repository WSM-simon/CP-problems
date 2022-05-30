#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

int N;
bool color[MxN];
vector<int> path[MxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        if (c == 'B') color[i] = 1;
    }
    for (int i=0;i<N-1; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        path[t1].push_back(t2);
        path[t2].push_back(t1);
    }
    
    return 0;
}
