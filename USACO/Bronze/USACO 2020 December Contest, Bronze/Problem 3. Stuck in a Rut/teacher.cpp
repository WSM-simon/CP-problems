#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int N;
pair<char, pair<int, int>> cows[51];
multimap<int, pair<int, int>> meeting;
vector<int> result(51, -1);
set<int> stuck;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>cows[i].first>>cows[i].second.first>>cows[i].second.second;
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; ++j){
            if(cows[i].first=='E'&&cows[j].first=='E'){
                continue;
            }
            if(cows[i].first=='N'&&cows[j].first=='N'){
                continue;
            }
            if(cows[i].first=='E' && cows[j].first=='N'){
                if(cows[i].second.first>cows[j].second.first || cows[j].second.second>cows[i].second.second)
                    continue;
                else{
                    int dx=abs(cows[j].second.first-cows[i].second.first);
                    int dy=abs(cows[i].second.second-cows[j].second.second);
                    if(dx>dy)
                        meeting.insert(make_pair(dx,make_pair(i, j)));
                    if(dx<dy)
                        meeting.insert(make_pair(dy,make_pair(i, j)));
                }
            }
            if(cows[i].first=='N' && cows[j].first=='E'){
                if(cows[j].second.first>cows[i].second.first || cows[i].second.second>cows[j].second.second)
                    continue;
                else{
                    int dx=abs(cows[j].second.first-cows[i].second.first);
                    int dy=abs(cows[i].second.second-cows[j].second.second);
                    if(dx>dy)
                        meeting.insert(make_pair(dx,make_pair(j, i)));
                    if(dx<dy)
                        meeting.insert(make_pair(dy,make_pair(j, i)));
                }
            }
        }
    }

    for(auto v : meeting){
        int x1=cows[v.second.first].second.first;
        int y1=cows[v.second.first].second.second;
        int x2=cows[v.second.second].second.first;
        int y2=cows[v.second.second].second.second;

        if(stuck.find(v.second.first)!=stuck.end() && x1+result[v.second.first]-1<x2)
            continue;
        if(stuck.find(v.second.second)!=stuck.end() && y2+result[v.second.second]-1<y1)
            continue;

        if(abs(x2-x1)==v.first){
            result[v.second.first] = v.first;
            stuck.insert(v.second.first);
        }
        if(abs(y2-y1)==v.first){
            result[v.second.second] = v.first;
            stuck.insert(v.second.second);
        }
    }

    for(int i=0; i<N; i++){
        if(result[i]==-1)
            cout<<"Infinity"<<'\n';
        else
            cout<<result[i]<<'\n';
    }

    return 0;
}
