#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 30;
const int inf = 0x3f3f3f3f;

int K;
bitset<Max> lights;

int count_1_around(bitset<Max> obj, int pos, int range)
{
    int counter = 0;
    // count forward
    for (int i = pos; i < pos + range; ++i)
        if (obj[i] == 1)
            counter++;
    // count backward
    for (int i = pos; i > pos - range; --i)
        if (obj[i] == 1)
            counter++;

    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int t;
        cin >> t;
        lights[i] = t;
    }
    int cnt = 0;
    while (!lights.none())
    {
        // p1 and p2 and the pos of first 1 and last 1
        int p1 = 0, p2 = K - 1;
        while (!lights[p1])
            p1++;
        while (!lights[p2])
            p2--;
        if (p2 - p1 < 4)
            cnt += 4 - lights.count(), lights.reset();
        else
        {
            // p0 is the best pos of zero in between (p1, p2)
            int p0=p1, p_influ = inf;
            for (int p = p1; p <= p2; ++p)
            {
                if (lights[p] == 0)
                {
                    int cnt1 = count_1_around(lights, p, 4);
                    if (cnt1 != 0 && cnt1 < p_influ)
                        p_influ = cnt1, p0 = p;
                }
            }
            // start changing
            lights[p0] = 1, cnt++;
            int st = p0, ed = p0, cnt1 = 1;
            while (st > 0)
            {
                if (lights[st - 1] == 1)
                    st--, cnt1++;
                else
                    break;
            }
            while (ed < K-1)
            {
                if (lights[ed+1] == 1)
                    ed++, cnt1++;
                else    
                    break;
            }
            if (cnt1 >= 4)
                for (int i = st; i <= ed; ++i)
                    lights[i] = 0;
        }
    }
    cout << cnt << '\n';
    return 0;
}
