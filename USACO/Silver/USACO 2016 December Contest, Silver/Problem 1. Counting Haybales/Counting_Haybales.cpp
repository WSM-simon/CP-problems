#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    // freopen("haybales.in", "r", stdin);
    // freopen("haybales.out", "w", stdout);


    int N, Q, u, l;
    cin >> N >> Q;

    int haybales[N];
    for (int i; i<N; i++)
        cin >> haybales[i];

    sort(haybales, haybales+N);

    for (int i; i<Q; i++)
        {
            cin >> l >> u;
            cout << (upper_bound(haybales, haybales+N, u) - find(haybales, haybales+N, l)) << '\n';
        }

    return 0;
}

    

