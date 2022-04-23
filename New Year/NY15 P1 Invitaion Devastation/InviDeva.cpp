#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string tem;
        cin >> tem;
        for (char c : s)
        {
            if (c == '>')
                cout << tem;
            else
                cout << c;
        }
        cout << '\n';
    }
    return 0;
}
