#include <bits/stdc++.h>
using namespace std;
// using set and iter, slow.


int K,M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K >> M;
    set<int> friends;
    for (int i=1; i<=K; i++)
        friends.insert(i);


    for (int i=0; i<M; i++){
        int r;
        cin >> r;
        
        bool once=true;
        auto p=friends.begin();
        vector<set<int>::iterator> removed;

        for (size_t j=r; j<=friends.size(); j+=r){
            if (!once){
                for (int z=0; z<r; z++){
                    p++;
                }
            }
            else{
                for (int z=0; z<r-1; z++){
                    p++;
                }
                once = false;
            }

            removed.push_back(p);
        }
        for (auto pp:removed)
            friends.erase(pp);
    }

    for (int i:friends)
        cout << i << '\n';
    return 0;
}