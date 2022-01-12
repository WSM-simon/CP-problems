#include <bits/stdc++.h>
using namespace std;
/*
    1 2 3 4 5 will be like 1 4 5 2 3. 
*/

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (1 < N & N < 4)
        cout << "NO SOLUTION";
    else if (N == 4)
        cout << "2 4 1 3 ";
    else
    {
        bool odd = (N & 1);
        int tem;
        for (int i = 0; i < N / 2; i++)
        {
            tem = i + 1;
            cout << tem << ' ';
            tem = i + N / 2 + 1 + (odd ? 1 : 0);
            cout << tem << ' ';
        }
        if (odd)
        {
            cout << N / 2 + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}