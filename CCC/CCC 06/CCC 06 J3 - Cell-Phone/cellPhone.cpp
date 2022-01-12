#include <bits/stdc++.h>
using namespace std;

string button[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int findPressTime(char c){
    int cntT=0;
    if (find(_1pw, _1pw+9, c) != _1pw+9)
        cntT++;
    else if (find(_2pw, _2pw+9, c) != _2pw+9)
        cntT+=2;
    else if (find(_3pw, _3pw+9, c) != _3pw+9)
        cntT+=3;
    else if (find(_4pw, _4pw+2, c) != _4pw+2)
        cntT+=4;
    
    return cntT;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string word;

    while(cin >> word){
        if (word == "halt")
            break;
        
        int cntT=0;
        for (size_t i=0; i<word.length()-1; i++){
            int w1=findPressTime(word[i]);
            int w2=findPressTime(word[i+1]);
            if (w1==w2)
                cntT+=2;
            cntT+=w1;
        }
        cntT+=findPressTime(*(word.end()-1));
        cout << cntT << '\n';
    }

    return 0;
}