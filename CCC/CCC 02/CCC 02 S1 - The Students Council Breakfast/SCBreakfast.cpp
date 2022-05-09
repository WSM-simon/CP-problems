#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, cnt = 0, minnum = 1e9;
int a, b, c, d;

array<int, 4> arr;
set<array<int, 4>> st;

bool solve(int n)
{
    if (n == 0)
    {
        if (st.find(arr) != st.end())
            return 0;
        st.insert(arr);
        cnt++;
        minnum = min(minnum, accumulate(arr.begin(), arr.end(), 0));
        cout << "# of PINK is " << arr[0] << " # of GREEN is " << arr[1] << " # of RED is " << arr[2] << " # of ORANGE is " << arr[3] << '\n';
        return 1;
    }
    if (n < 0)
        return 0;
    arr[0]++;
    solve(n - a);
    arr[0]--;
    arr[1]++;
    solve(n - b);
    arr[1]--;
    arr[2]++;
    solve(n - c);
    arr[2]--;
    arr[3]++;
    solve(n - d);
    arr[3]--;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d >> N;
    solve(N);
    cout << "Total combinations is " << cnt << ".\n";
    cout << "Minimum number of tickets to print is " << minnum << ".\n";
    return 0;
}
