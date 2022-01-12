#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N, M;
int main()
{
    int N, 
    int cnt = 0;
    cin >> N >> M;
    for (int i = N; i <= M; ++i)
    {
        bool pass = 1;
        string s = to_string(i);
        int sz = s.size();
        bool odd = sz % 2;
        for (int j = 0; j < sz; ++j)
        {
            if (odd && (j == sz / 2 + 1))
                if (s[j] == '1' || s[j] == '8' || s[j] == '0')
                    continue;
            if (!(s[j] == '1' || s[j] == '8' || s[j] == '9' || s[j] == '6' || s[j] == '0'))
            {
                pass = 0;
                break;
            }
            if (s[j] == '1' && s[sz - j - 1] != '1')
            {
                pass = 0;
                break;
            }
            if (s[j] == '8' && s[sz - j - 1] != '8')
            {
                pass = 0;
                break;
            }
            if (s[j] == '0' && s[sz - j - 1] != '0')
            {
                pass = 0;
                break;
            }
            if (s[j] == '6' && s[sz - j - 1] != '9')
            {
                pass = 0;
                break;
            }
            if (s[j] == '9' && s[sz - j - 1] != '6')
            {
                pass = 0;
                break;
            }
        }
        if (pass)
            ++cnt;
    }
    cout << cnt;
    return 0;
}