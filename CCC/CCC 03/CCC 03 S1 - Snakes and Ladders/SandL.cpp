#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    map<int, int> move={{54,19}, {90,48}, {99,77}, {9,34}, {40, 64}, {67,86}};

    int pos=1;
    int dice;
    while(cin>>dice){
        if (dice == 0){
            cout << "You Quit!";
            break;
        }
        if (move.find(pos+dice)!=move.end()){
            pos = move[pos+dice];
            cout << "You are now on square " << pos << '\n';
        }
        else if (pos+dice<100){
            pos+=dice;
            cout << "You are now on square " << pos << '\n';
        }
        else if (pos+dice==100){
            pos+=dice;
            cout << "You are now on square 100" << '\n';
            cout << "You Win!" << '\n';
            break;
        }
        else
            cout << "You are now on square " << pos << '\n';
    }
    return 0;
}