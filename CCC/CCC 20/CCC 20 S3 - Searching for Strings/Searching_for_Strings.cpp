#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const ull A=43, B=1e9+7;

bool ifSameFreq(map<char, int> freq1, map<char, int> freq2){
    for (char c='a'; c<='z'; c++){
        if (freq1[c] != freq2[c]){
            return false;
        }
    }
    return true;
}

void prefix_rollingHash(ull prefix[], string haystack, int lenHay){
    prefix[0] = 1ull*(haystack[0]-'a'+1);
    for (int i=1; i<lenHay; i++){
        prefix[i] = (prefix[i-1]*A + 1ull*(haystack[i]-'a'+1))%B;
    }
}

ull getHash(ull prefix[], ull multipliesA, int beg, int ed){
    if (beg==0)
        return prefix[ed-1];
    else{
        return (prefix[ed-1] - ((prefix[beg-1]*multipliesA)%B) + B)%B;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);

    string needle, haystack;
    cin >> needle >> haystack;
    
    int lenN = needle.length(), lenHay = haystack.length();
    map<char, int> freqN, freqStr;
    map<ull, string> used;

    string subStr = haystack.substr(0, lenN);
    ull prefix[lenHay];
    ull multipliesA = 1ull;
    for (int i=0; i<lenN; i++) multipliesA *= A;
    prefix_rollingHash(prefix, haystack, lenHay);

    for (char c:needle) freqN[c]++;
    for (char c:subStr) freqStr[c]++;
    for (int i=0; i<lenHay-lenN+1; i++){
        if (ifSameFreq(freqN, freqStr)){
            if (subStr == "llnlnlln")
                cout << "111" << '\n';
            ull hash_subS = getHash(prefix, multipliesA, i, i+lenN);
            if (used.find(hash_subS)==used.end()){
                used[hash_subS] = subStr;
            }
            else if (used[hash_subS] != subStr){
                ull i=0;
                while(i++){
                    if (used[hash_subS+i] == subStr)
                        break;
                    else if (used.find(hash_subS+i) == used.end()){
                        used[hash_subS+i] = subStr;
                        break;
                    }
                }
            }
        }

        subStr = haystack.substr(i+1, lenN);
        char added = haystack[i+lenN], removed = haystack[i];
        freqStr[added]++;
        freqStr[removed]--;
    }

    cout << used.size() << '\n';
    
    map<string, vector<ull>> map_test;
    for (auto p:used){
        map_test[p.second].push_back(p.first);
    }

    cout << map_test.size();
    return 0;
}