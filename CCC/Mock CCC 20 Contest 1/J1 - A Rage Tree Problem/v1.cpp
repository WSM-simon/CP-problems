#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    cout << *min_element(arr, end(arr)) << '\n';
    cout << *max_element(arr, end(arr)) << '\n';
    
    return 0;
}
