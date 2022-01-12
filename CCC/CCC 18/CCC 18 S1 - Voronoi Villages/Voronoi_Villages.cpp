#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int N;

int main() {
    int village[101]={0};

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> village[i];
    }
    
    sort(village, village+N);

    int mindist = INT32_MAX;
    for (int i=0; i<N-2; i++){
        int tem = village[i+2]-village[i];
        if (tem < mindist) mindist = tem;
    }

    cout << fixed << setprecision(1) << mindist/2.0;
    return 0;
}