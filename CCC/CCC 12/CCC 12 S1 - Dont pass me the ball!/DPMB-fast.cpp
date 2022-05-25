#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cout << ((N-1)*(N-2)*(N-3)/6) << '\n';
    return 0;
}
