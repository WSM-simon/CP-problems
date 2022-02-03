#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;

int N, M, ans[Max][13], negscore[Max], minmaxnegscore = 1e9 + 3;

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
            if (c == 'T')
                ans[i][j] = 1;
        }

    for (int j = 0; j < (1 << M); ++j)
    {
        int maxnegscore = 0;
        memset(negscore, 0, sizeof(negscore));
        vector<int> key = generate_answer_key(j);
        for (int k = 0; k < M; ++k)
        {
            for (int i = 0; i < N; ++i)
            {
                if (ans[i][k] != key[k])
                    negscore[k]++, maxnegscore = max(maxnegscore, negscore[k]);
            }
        }
        minmaxnegscore = min(minmaxnegscore, maxnegscore);
    }
    cout << M - minmaxnegscore << '\n';
    return 0;
}
