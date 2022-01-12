#include <bits/stdc++.h>
using namespace std;

int N;
int swi[1000001], sem[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cntMax=0;
    cin >> N;

    for (int i=0; i<N; i++) cin >> swi[i];
    for (int i=0; i<N; i++) cin >> sem[i];

    for (int i=1; i<N; i++) swi[i] = swi[i-1]+swi[i];
    for (int i=1; i<N; i++) sem[i] = sem[i-1]+sem[i];

    for (int i=0; i<N; i++){
        if (swi[i] == sem[i] && i+1 > cntMax){
            cntMax = i+1;
        }
    }  

    cout << cntMax;
    return 0;
}