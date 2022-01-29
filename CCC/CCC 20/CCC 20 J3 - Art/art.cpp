#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;

int N, xMin = 1e9 + 3, xMax = 0, yMin = 1e9 + 3, yMax = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x, y, k;
        string s;
        cin >> s;
        k = s.find(',');
        x = stoi(s.substr(0, k));
        y = stoi(s.substr(k + 1));
        xMax = max(xMax, x);
        xMin = min(xMin, x);
        yMax = max(yMax, y);
        yMin = min(yMin, y);
    }
    cout << xMin - 1 << ',' << yMin - 1 << '\n';
    cout << xMax + 1 << ',' << yMax + 1 << '\n';
    return 0;
}
