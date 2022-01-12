#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, P[Max], T[Max], D[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> P[i];
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        D[i] = P[i] - t;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        // search for the
        while (D[i] > 0)
        {
            vector<int> e = {i};
            int add = D[i];
            for (int j = i + 1; D[j] > 0 && j < N; ++j)
            {
                add = min(add, D[j]);
                e.push_back(j);
            }
            for (int i : e)
                D[i] -= add;
            cnt += add;
        }
        while (D[i] < 0)
        {
            vector<int> e = {i};
            int sub = D[i];
            for (int j = i + 1; D[j] < 0 && j < N; ++j)
            {
                sub = max(sub, D[j]);
                e.push_back(j);
            }
            for (int i : e)
                D[i] -= sub;
            cnt -= sub;
        }
    }
    cout << cnt;
    return 0;
}