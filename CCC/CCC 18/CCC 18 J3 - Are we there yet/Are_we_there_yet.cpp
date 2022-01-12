#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> p(5,0);
    for (int i=1; i<5; i++){
        cin >> p[i];
        p[i] += p[i-1];
    }

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cout << abs(p[i]-p[j]) << ' ';
        }
        cout << "\n";
    }

    return 0;
}