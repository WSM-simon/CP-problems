#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool ifconform(string perm[], vector<pair<string, string>> order){
    int k_ind=0;
    for (auto p:order){
        string p1=p.first, p2=p.second;
        k_ind = find(perm, perm+8, p1) - perm;

        if (k_ind==0){
            if (p2==perm[k_ind+1])
                continue;
            else return false;
        }

        else if (k_ind==7){
            if (p2==perm[k_ind-1])
                continue;
            else return false;
        }

        else{
            if ((p2==perm[k_ind-1]) || (p2==perm[k_ind+1]))
                continue;
            else return false;
        } 
    }
    return true;
}

void jump(){
    string t;
    for (int i=0; i<4; i++){
        cin >> t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n=0;
    string c1, c2;
    string name[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    
    cin >> n;
    vector<pair<string, string>> order;

    for (int i=0; i<n; i++){
        cin >> c1;
        jump();
        cin >> c2;
        order.push_back(make_pair(c1, c2));
    }

    sort(begin(name), end(name));

    do{
        if (ifconform(name, order)){
            for (string s:name){
                cout << s << '\n';
            }
            break;
        }
    }while(next_permutation(name, name+8));

    return 0;
}