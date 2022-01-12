#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, P[Max], T[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> P[i];
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    int st = 0, ed = N - 1, cnt = 0;
    while (true)
    {
        int diff_st = P[st] - T[st], diff_ed = P[ed] - T[ed];
        if (abs(diff_st) > abs(diff_ed))
        {
            for (int i = st; i <= ed; ++i)
                T[i] += diff_ed;
            ed--, cnt += abs(diff_ed);
        }

        else if (abs(diff_st) < abs(diff_ed))
        {
            for (int i = st; i <= ed; ++i)
                T[i] += diff_st;

            st++, cnt += abs(diff_st);
        }

        else // diff_st == diff_ed
        {
            for (int i = st; i <= ed; ++i)
                T[i] += diff_st;
            cnt += abs(diff_st);
            if (st + 1 == ed)
                break;
            if (st == ed)
                break;
            st++, ed--;
        }
    }
    cout << cnt;
    return 0;
}