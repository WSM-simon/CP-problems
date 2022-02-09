#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max1 = 1e6;
const int Max2 = 1003;
const int inf = 0x3f3f3f3f;

int H, K, house[Max2];

bool check_start_p(int n, int p)
{
    // To make sure the house cpy has a new order of houses
    int house_cpy[1003];
    memcpy(house_cpy, house, 4*H);
    for (int i = 0; i < p; ++i)
        house_cpy[i] += Max1;
    sort(house_cpy, house_cpy + H);

    // place a hydrant on p's right side at a distance of n
    // therefore the houses between p and p2 will have water
    int p1 = house_cpy[0], p2 = p1 + 2 * n, k = K - 1;
    while (p2 < house_cpy[H - 1])
    {
        for (int i = 0; i < H; ++i)
        {
            if (house_cpy[i] > p2)
            {
                p1 = house_cpy[i], p2 = p1 + 2 * n;
                // place down a new hydrant
                if (--k < 0)
                    return 0;
                break;
            }
        }
    }
    return 1;
}

// sadly, because this street is a circle, we have to try to check all the houses as beginning.
bool check(int n)
{
    for (int i = 0; i < H; ++i)
        if (check_start_p(n, i))
            return 1;
    return 0;
}

int binary_search(int st, int ed)
{
    while (st < ed - 1)
    {
        int mid = st + ((ed - st) >> 1);
        if (check(mid))
            ed = mid;
        else
            st = mid;
    }
    if (check(st))
        return st;
    else
        return ed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H;
    for (int i = 0; i < H; ++i)
        cin >> house[i];
    sort(house, house + H);
    cin >> K;
    int ans = binary_search(0, Max1);
    cout << ans;
    return 0;
}
