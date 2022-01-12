#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 200001;
int in[Max], out[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> in[i] >> out[i];

    sort(in, in + n);
    sort(out, out + n);

    int Cmax = 0;
    for (int i = 0, j = 0, z = 0; i < n && j < n && z >= 0;)
    {
        if (in[i] < out[j])
            z++, i++;
        else if (out[j] < in[i])
            z--, j++;
        else
            i++, j++;
        Cmax = max(Cmax, z);
    }
    cout << Cmax;
    return 0;
}