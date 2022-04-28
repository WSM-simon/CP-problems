#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>
#define scan(x)                                                                   \
    do                                                                            \
    {                                                                             \
        while ((x = getchar()) < '0')                                             \
            ;                                                                     \
        for (x -= '0'; '0' <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - '0') \
            ;                                                                     \
    } while (0)
char _;

using namespace std;

const int MxN = 5e5 + 3;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int N, M;
vector<int> arr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N);
    scan(M);
    for (int i = 0; i < N; ++i)
    {
        int tem;
        scan(tem);
        arr.push_back(tem);
    }
    sort(arr.begin(), arr.end());
    list<int> ans(arr.begin(), arr.end());
    for (auto i = ans.begin(), j = --ans.end(); i != --ans.end(), j != ans.begin(); i++)
    {
        auto i2 = i;
        i2++;
        if (*i + *(i2) >= M)
            continue;
        if (*i + *j < M)
        {
            cout << "-1\n";
            exit(0);
        }
        while (*i + *j >= M)
            j--;
        j++;
        int j_v = *j;
        ans.erase(j);
        ans.insert(i2, j_v);
        j++;
    }
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}
