#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e6+3;

int N, SUM=0, arr[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i)
    {
        int t;
        cin >> t;
        SUM+=t;
        arr[i]=t;
    }
    if (SUM % 2 == 1)
    {
        cout << "Andrew is sad.\n";
        return 0;
    }
    int MID = SUM/2, cnt=0;
    while(MID != 0)
    {
        MID -= arr[cnt];
        cnt++;
        if (MID < 0)
        {
            cout << "Andrew is sad.\n";
            return 0;
        }
    }
    cout << cnt << '\n';
    return 0;
}
