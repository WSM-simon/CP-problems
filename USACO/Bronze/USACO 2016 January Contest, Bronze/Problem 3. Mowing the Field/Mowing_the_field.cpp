#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>


using namespace std;

void FJsearch(pair<int, int> &node, map<pair<int,int>, int> &cutted, vector<int> &g_speed, int &cnt, char d, int m){
    int x=node.first, y=node.second;
    for(int i=0; i<m; i++){
        cnt ++;
        if (d == 'N') x++;
        else if (d == 'S') x--;
        else if (d == 'E') y--;
        else if (d == 'W') y++;
        
        node = make_pair(x, y);
        if (cutted.find(node) != cutted.end()) g_speed.push_back(cnt - cutted[node]);
        
        cutted[node] = cnt;
    }
}


int main(){
    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.out", "w", stdout);

    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n, m, cnt=0;
    char d;
    pair<int, int> node;
    map<pair<int,int>, int> cutted;
    vector<int> g_speed;

    cin >> n;
    for(int i; i<n; i++){
        cin >> d >> m;
        FJsearch(node, cutted, g_speed, cnt, d, m);
    }

    if(g_speed.size()){
        cout << *min_element(g_speed.begin(), g_speed.end());
    }
    else cout << -1;

    return 0;
}