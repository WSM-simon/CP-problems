#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
vector<string> seg;

bool is_str(char c) { return (c >= 65 && c <= 90); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string data;
    cin >> data;

    N = (int)data.size();
    string s = "";

    for (int i = 0; i < N; ++i)
    {
        s += data[i];
        if (i == N - 1)
        {
            seg.push_back(s);
            s = "";
            continue;
        }
        if (!is_str(data[i]) && is_str(data[i + 1]))
        {
            seg.push_back(s);
            s = "";
            continue;
        }
    }
    for (string tem : seg)
    {
        for (int i = 0; i < (int)tem.size(); ++i)
        {
            char c = tem[i];
            if (is_str(c))
                cout << c;
            if (c == '+')
            {
                cout << " tighten ";
                for (int j = i + 1; j < (int)tem.size(); ++j)
                    cout << tem[j];
                cout << '\n';
                break;
            }
            if (c == '-')
            {
                cout << " loosen ";
                for (int j = i + 1; j < (int)tem.size(); ++j)
                    cout << tem[j];
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}
