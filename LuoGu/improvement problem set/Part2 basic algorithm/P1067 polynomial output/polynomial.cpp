#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5+3;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i=N; i>=0; i--)
    {
        int co;
        cin >> co;
        if (co == 0)
            continue;
        if (co>0 && i != N)
            cout << "+";
        if (i == 0)
        {
            cout << co;
            return 0;
        }
        if (co != 1)
        {
            if (co == -1)
            {
                cout << "-";
            }
            else cout << co;    
        } 
        if (i == 1)
            cout << 'x';
        else
            cout << "x^" << i;
    }
    return 0;
}
