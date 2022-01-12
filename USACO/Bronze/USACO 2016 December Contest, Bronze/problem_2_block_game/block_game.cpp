#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

int main(){
    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.out", "w", stdout);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N, alphabet[26] = {0};
    string c1, c2;

    cin >> N;
    while(N--){
        cin >> c1 >> c2;
        for(int i=0; i<=25; i++){
            int a = count(c1.begin(), c1.end(), char(97+i));
            int b = count(c2.begin(), c2.end(), char(97+i));

            alphabet[i] += max(a,b);
            // cout << c1 << ' ' << char(97+i) <<' ' << a << endl;
            // cout << c2 << ' ' << char(97+i) <<' ' << b << endl;
        }
    }
    for(int i:alphabet){
        cout << i << "\n";
    }
}