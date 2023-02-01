#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;

int N, M, ans[Max][13], negscore[Max];

// You actually don't need to change a number to binary, you can just use xor to compare two ints. Such as, one student's answer is 10101(2) = 21
// the key you generate is 22 = 10110(2), so 21^22 = 00011(2) = 3. For efficency, you can also use __builtin_popcount to count all the 1s in 21^22 quickly.
vector<int> generate_answer_key(int n)
{
    vector<int> key;
    bitset<13> b = n;
    for (int i = 0; i < M; ++i)
        key.push_back(b[i]);
    return key;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            char c;
            cin >> c;
            ans[i][j] = (c == 'T' ? 1 : 0);
        }

    int minmaxnegscore = 1e9 + 3;
    for (int i = 0; i < (1 << M); ++i)
    {
        memset(negscore, 0, sizeof(negscore));
        int maxnegscore = 0;
        vector<int> key = generate_answer_key(i);
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < M; ++c)
            {
                if (ans[r][c] != key[c])
                {
                    negscore[r]++;
                    maxnegscore = max(maxnegscore, negscore[r]);
                }
            }
        }
        minmaxnegscore = min(minmaxnegscore, maxnegscore);
    }
    cout << M - minmaxnegscore << '\n';
    return 0;
}
