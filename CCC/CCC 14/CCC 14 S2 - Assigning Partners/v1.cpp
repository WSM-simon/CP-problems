#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N;
map<string, string> mp;
vector<string> v1, v2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string tem;
        cin >> tem;
        v1.push_back(tem);
    }
    for (int i = 0; i < N; ++i) {
        string tem;
        cin >> tem;
        v2.push_back(tem);
    }
    for (int i = 0; i < N; ++i) {
        if (v1[i] == v2[i]) {
            cout << "bad\n";
            return 0;
        }
        if (mp[v1[i]] == "" && mp[v2[i]] == "") {
            mp[v1[i]] = v2[i];
            mp[v2[i]] = v1[i];
        } else if (mp[v1[i]] != v2[i]) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "good\n";
    return 0;
}
