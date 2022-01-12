#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int num_H, num_V;
    bool H,V;
    string flips;
    cin >> flips;
    
    num_H = count(flips.begin(), flips.end(), 'H');
    num_V = flips.length()-num_H;

    H = num_H%2 != 0;
    V = num_V%2 != 0;

    if (H && V) cout << "4 3\n2 1";
    else if (H) cout << "3 4\n1 2";
    else if (V) cout << "2 1\n4 3";
    else cout << "1 2\n3 4";

    return 0;
}