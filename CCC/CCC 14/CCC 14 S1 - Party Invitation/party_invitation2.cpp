#include <bits/stdc++.h>
using namespace std;

bitset<101> friends;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    friends.set();

    int K, M;
    cin >> K >> M;
    for (int i=0; i<M; i++){ 
        int cntP=0;
        int r;
        cin >> r;
        for (int j=0; j<= K; j++){
            if (friends[j])
                cntP++;
            if (cntP==r){
                friends[j].flip();
                cntP=0;
            }                
        }
    }

    for (int i=0; i<K; i++)
        if (friends[i])
            cout << i+1 << '\n';
    return 0;
}