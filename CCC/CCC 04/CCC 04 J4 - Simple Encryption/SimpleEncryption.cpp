#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string key, s1, s2="", s3="";
    getline(cin, key);
    getline(cin, s1);
    for (char c:s1)
        if (c>=65 && c<=90)
            s2+=c;
    for (int i=0; i<(int)s2.size(); ++i)
    {
        char c = key[i%(int)key.size()]-'A'+s2[i];
        if (c>90)
            c-=26;
        s3+=c;
    }
    cout << s3;
    return 0;
}
