#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i < N - 1; ++i)
    {
        if (s[i] < s[i + 1])
        {
            swap(s[i], s[i + 1]);
            break;
        }
    }
    cout << s << '\n';
    return 0;
}
