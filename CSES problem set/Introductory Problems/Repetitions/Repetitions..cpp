#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    int cnt=1, cntMax=1;
    string s;
    cin >> s;
    for (size_t i=0; i<s.length()-1; i++){
        if (s[i]==s[i+1]){
            cnt++;
            if (cnt>cntMax)
                cntMax=cnt;
        }
        else
            cnt=1;
    }
    cout << cntMax;
    return 0;
}