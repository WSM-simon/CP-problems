#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
string names[MxN];
bool status[MxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int tem;
        string name;
        cin >> tem >> name;
        status[i] = tem;
        names[i] = name;
    }

    int ptr = 0;
    for (int i = 0; i < M; ++i)
    {
        int s, m;
        cin >> s >> m;
        if (s != status[ptr])
            ptr = (ptr + m) % (N);
        else
        {
            if (ptr >= m)
                ptr -= m;
            else
                ptr = N - (m - ptr) % N;
        }
    }
    cout << names[ptr] << '\n';
    return 0;
}
