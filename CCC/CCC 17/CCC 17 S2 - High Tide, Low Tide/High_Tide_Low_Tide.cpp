#include <bits/stdc++.h>
using namespace std;

int N;
int tide[10000001], lower_tide[500002], higher_tide[500002];

bool sort_lower (int i,int j) { return (i>j); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i=0; i<N; i++)
        cin >> tide[i];

    sort(tide, tide+N);

    if ((N&1)==1){
        int midNum = (N+1)/2;
        memcpy(lower_tide, tide, midNum*sizeof(int));
        memcpy(higher_tide, tide+midNum, (midNum-1)*sizeof(int));
        sort(lower_tide, lower_tide+midNum, sort_lower);
    }
    
    else{
        int midNum = N/2;
        memcpy(lower_tide, tide, midNum*sizeof(int));
        memcpy(higher_tide, tide+midNum, midNum*sizeof(int));
        sort(lower_tide, lower_tide+midNum, sort_lower);
    }
    
    
    for (int i=0; i<N/2; i++){
        cout << lower_tide[i] << ' ';
        cout << higher_tide[i] << ' ';
    }

    if ((N&1)==1){
        cout << *(begin(lower_tide)+N/2);
    }

    return 0;
}