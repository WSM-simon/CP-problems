#include <bits/stdc++.h>
using namespace std;

bool ifSameFreq(map<char, int> freq1, map<char, int> freq2){
    for (char c='a'; c<='z'; c++){
        if (freq1[c] != freq2[c]){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);

    string needle, haystack;
    cin >> needle >> haystack;
    
    int lenN = needle.length(), lenHay = haystack.length();
    map<char, int> freqN, freqStr;
    map<size_t, bool> used;

    int cnt=0;
    string subStr = haystack.substr(0, lenN);
    hash<string> hasher;

    for (char c:needle) freqN[c]++;
    for (char c:subStr) freqStr[c]++;
    for (int i=0; i<lenHay-lenN+1; i++){
        if (ifSameFreq(freqN, freqStr)){
            size_t hash_subS = hasher(subStr);
            if (!used[hash_subS]){
                used[hash_subS] = true;
                cnt++;
            }
        }

        subStr = haystack.substr(i+1, lenN);
        char added = haystack[i+lenN], removed = haystack[i];
        freqStr[added]++;
        freqStr[removed]--;
    }

    cout << cnt;
    return 0;
}