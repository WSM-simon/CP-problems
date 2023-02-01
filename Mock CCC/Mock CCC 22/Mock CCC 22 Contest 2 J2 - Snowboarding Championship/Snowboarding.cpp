#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;

int N, A, B, finA = 0, finB = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> B;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a >= A)
            finA += 2;
        else
            finA++;

        if (b >= B)
            finB += 2;
        else
            finB++;
    }
    if (finA > finB)
        cout << "Tommy wins!" << '\n';
    if (finA < finB)
        cout << "Andrew wins!" << '\n';
    if (finA == finB)
        cout << "Tie!" << '\n';

    return 0;
}
