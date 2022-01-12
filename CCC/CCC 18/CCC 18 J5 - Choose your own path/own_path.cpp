#include <bits/stdc++.h>
using namespace std;

int N, M;

pair<bool, int> bfs_search(unordered_map<int, vector<int>> path, unordered_set<int> endings){
    queue<pair<int, int>> que;
    que.push(make_pair(1, 0));
    unordered_set<int> visited;
    visited.insert(1);

    bool go=true;
    int shortest_route=1;

    while (!que.empty()){
        pair<int, int> vertex = que.front();
        que.pop();
        vector<int> node = path[vertex.first];

        for (int v:node){
            if (go && (endings.find(v) != endings.end())){
                shortest_route = vertex.second+2;
                visited.insert(v);
                go = false;
            }
            else if (visited.find(v) == visited.end()){
                que.push(make_pair(v, vertex.second+1));
                visited.insert(v);
            }
        }
    }

    if (visited.size()==1ull*N)
        return make_pair(true, shortest_route);
    else
        return make_pair(false, shortest_route);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<int> endings;
    unordered_map<int, vector<int>> path;
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> M;
        if (M!=0){
            int v;
            vector<int> temV;

            for (int j=0; j<M; j++){
                cin >> v; 
                temV.push_back(v);
            } 
            path.insert(make_pair(i+1, temV));
        }
        else
            endings.insert(i+1);
    }

    pair<bool, int> ans= bfs_search(path, endings);

    cout << ((ans.first) ? 'Y':'N') << '\n' << ans.second;

    return 0;
}