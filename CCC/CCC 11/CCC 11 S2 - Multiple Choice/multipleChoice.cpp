#include <bits/stdc++.h>
using namespace std;

int N;
char stu[10001]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    int cnt=0;

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> stu[i];
    }

    for (int i=0; i<N; i++){
        char tem;
        cin >> tem;
        if (tem == stu[i])
            cnt++;
    }

    cout << cnt;
    return 0;
}