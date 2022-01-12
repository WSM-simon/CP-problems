#include <iostream>
#include <bitset>

using namespace std;

const int l = 400000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K, x;
    int r=0, c=0;
    char q;

    cin >> M >> N >> K;

    bitset<l> row; bitset<l> col;
    
    for(int i=0; i<K; i++)
    {
        cin >> q >> x;
        x--;
        if(q=='R') row.flip(x);
        else col.flip(x);
    }

    r = row.count();
    c = col.count();
    
    cout << r*N + c*M - 2*r*c;
}