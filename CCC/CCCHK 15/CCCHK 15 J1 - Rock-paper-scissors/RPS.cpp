#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, Alice[1000], Bob[1000];
int check[3][3] = {{0, -1, 1}, {1, 0, -1}, {-1, 1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i)
    {
        string s;
        cin >> s;
        if (s == "rock")
            Alice[i] = 0;
        if (s == "paper")
            Alice[i] = 1;
        if (s == "scissors")
            Alice[i] = 2;
    }
    for (int i=0; i<N; ++i)
    {
        string s;
        cin >> s;
        if (s == "rock")
            Bob[i] = 0;
        if (s == "paper")
            Bob[i] = 1;
        if (s == "scissors")
            Bob[i] = 2;
    }
    int score_a = 0, score_b = 0;
    for (int i=0; i<N; ++i)
    {
        if (check[Alice[i]][Bob[i]] == 1)
            score_a++;
        if (check[Alice[i]][Bob[i]] == 0)
            continue;
        if (check[Alice[i]][Bob[i]] == -1)
            score_b++;
    }
    cout << score_a << ' ' << score_b << '\n';
    return 0;
}
