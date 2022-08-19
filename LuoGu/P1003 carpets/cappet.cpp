#include <bits/stdc++.h>
#define ll long long
#define ar4 array<int,4>

using namespace std;

const int MxN = 1e5+3;

int N;
vector<ar4> carpets;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; ++i)
    {
        int x, y, dx, dy;
        cin >> x >> y >> dx >> dy;
        carpets.push_back({x, y, dx, dy});
    }
    int xx, yy;
    cin >> xx >> yy;
    for (int i=carpets.size()-1; i>=0; i--)
    {
        if (xx >= carpets[i][0] && yy >= carpets[i][1])
            if (xx-carpets[i][0] <= carpets[i][2] && yy-carpets[i][1] <= carpets[i][3])
            {
                cout << i << '\n';
                return 0;
            }
    }
    return 0;
}
