#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string line;
    int cntT=0;
    int cntS=0;

    cin >> N;
    cin.ignore();
    for (int i=0; i<N; i++){
        getline(cin, line);
        cntT += count(line.begin(), line.end(), 't');
        cntT += count(line.begin(), line.end(), 'T');
        cntS += count(line.begin(), line.end(), 's');
        cntS += count(line.begin(), line.end(), 'S');
    }    

    cout << (cntS>=cntT ? "French":"English");
    return 0;
}