#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 103;
const int inf = 0x3f3f3f3f;

int N;
double villages[Max], points[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> villages[i];
    sort(villages, villages + N);
    for (int i = 0; i < N - 1; ++i)
        points[i] = (villages[i + 1] - villages[i]) / 2;
    double minivillage = inf;
    for (int i = 0; i < N - 2; ++i)
        minivillage = min(minivillage, points[i] + points[i + 1]);
    cout << fixed << setprecision(1) << minivillage << '\n';
    return 0;
}
