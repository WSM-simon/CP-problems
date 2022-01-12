#include <bits/stdc++.h>
#define pss pair<string, string>
using namespace std;
struct str;

int K;
string s1, s2;
pss rule[3];
map<string, vector<str>> memo;

struct str{
    short ruleUsed;
    short appliedP;
    string itself;
};

vector<str> findNextStr(string s1){
    vector<str> nextStr;
    for (int i=0; i<3; i++){
        pss r = rule[i];
        size_t pos = s1.find(r.first);
        while(pos != string::npos){
            str strfound;
            strfound.ruleUsed = i+1;
            strfound.appliedP = pos+1;
            strfound.itself = s1.substr(0, pos)+r.second+s1.substr(pos+r.first.length());

            nextStr.push_back(strfound);
            pos = s1.find(r.first, pos+1);
        }
    }
    return nextStr;
}

queue<str> bfs(int K, string s1, string s2){
    int cnt=1;
    queue<str> q;
    map<str, str> parent;
    vector<str> nextStr = findNextStr(s1);
    memo[s1]=nextStr;
    str s2_str;

    for (str s:nextStr){
        str tempS={-1, -1, s1};
        q.push(s);
        parent[s] = tempS;
    } 
    
    while (cnt <= K){
        int n=q.size();
        for (int i=0; i<n; i++){
            str strS = q.front(); q.pop();

            if (memo.find(strS.itself) != memo.end())
                nextStr = memo[strS.itself];
            
            else{
                nextStr = findNextStr(strS.itself);
                memo[strS.itself]=nextStr;
            }

            for (str s:nextStr){
                q.push(s);
                if (parent.find(strS) != parent.end()){
                    parent[s]=strS;
                    if (s.itself == s2 && cnt == K){
                        s2_str=s;
                    }
                }
            }
        }
        cnt++;
    }

    queue<str> ansInOrder;
    str strPar = parent[s2_str];
    ansInOrder.push(s2_str);

    for (int i=0; i<K-1; i++){
        str strPar = parent[strPar];
        ansInOrder.push(strPar);
    }
    return ansInOrder;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s1, s2;
    for (int i=0; i<3; i++){
        cin >> s1 >> s2;
        rule[i]=make_pair(s1, s2);
    }
    
    cin >> K >> s1 >> s2;
    // input over
    queue<str> ans = bfs(K, s1, s2);

    for (int i=0; i<K; i++){
        str strT=ans.front(); ans.pop();
        cout <<  strT.ruleUsed << ' ' << strT.appliedP << ' ' << strT.itself << '\n';
    }
    return 0;
}