#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    double S=0;

    cin >> N;
    int hight[N+2];

    for (int i=0, tem; i<N+1; i++){
        cin >> tem;
        hight[i] = tem;
    }

    for (int i=0, tem; i<N; i++){
        cin >> tem;
        S += (hight[i]+hight[i+1])*tem;
    }

    cout << fixed << S/2.0;
    return 0;
}