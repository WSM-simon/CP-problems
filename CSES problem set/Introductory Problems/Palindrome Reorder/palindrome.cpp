#include <bits/stdc++.h>
#define ll long long
#define pii pair<int int>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unordered_map<char, int> alphabet;
    
    string s;
    cin >> s;
    for (char c : s)
        alphabet[c]++;

    unordered_set<char> cntOdd;
    for (auto i : alphabet)
        if (i.second % 2 == 1)
            cntOdd.insert(i.first);

    if ((s.length() % 2 == 1) && (cntOdd.size() == 1))
    {
        char odd = *(cntOdd.begin());
        string tem = "";

        for (auto i : alphabet)
            if (i.first != odd)
                for (int j = 0; j < i.second / 2; j++)
                    tem += i.first;

        cout << tem;
        for (int i = 0; i < alphabet[odd]; i++)
            cout << odd;
        reverse(tem.begin(), tem.end());
        cout << tem;
    }

    else if ((s.length() % 2 == 0) && (cntOdd.size() == 0))
    {
        string tem;
        for (auto i : alphabet)
            for (int j = 0; j < i.second / 2; j++)
                tem += i.first;

        cout << tem;
        reverse(tem.begin(), tem.end());
        cout << tem;
    }

    else
        cout << "NO SOLUTION";
    

    return 0;
}