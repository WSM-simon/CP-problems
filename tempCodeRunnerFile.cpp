#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

vector<char> hand_C, hand_D, hand_H, hand_S;
map<char, int> worth = {{'A', 4}, {'K', 3}, {'Q', 2}, {'J', 1}};
int points_C = 0, points_D = 0, points_H = 0, points_S = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    char now = 'C';
    for (char c : s)
    {
        if (c == 'C' || c == 'D' || c == 'H' || c == 'S')
        {
            now = c;
            continue;
        }
        if (now == 'C')
        {
            if (worth.find(c) != worth.end())
                points_C += worth[c];
            hand_C.push_back(c);
        }
        if (now == 'D')
        {
            if (worth.find(c) != worth.end())
                points_D += worth[c];
            hand_D.push_back(c);
        }
        if (now == 'H')
        {
            if (worth.find(c) != worth.end())
                points_H += worth[c];
            hand_H.push_back(c);
        }
        if (now == 'S')
        {
            if (worth.find(c) != worth.end())
                points_S += worth[c];
            hand_S.push_back(c);
        }
    }
    // hand C
    if (hand_C.size() == 0)
        points_C += 3;
    if (hand_C.size() == 1)
        points_C += 2;
    if (hand_C.size() == 2)
        points_C += 1;
    // hand D
    if (hand_D.size() == 0)
        points_D += 3;
    if (hand_D.size() == 1)
        points_D += 2;
    if (hand_D.size() == 2)
        points_D += 1;
    // hand H
    if (hand_H.size() == 0)
        points_H += 3;
    if (hand_H.size() == 1)
        points_H += 2;
    if (hand_H.size() == 2)
        points_H += 1;
    // hand S
    if (hand_S.size() == 0)
        points_S += 3;
    if (hand_S.size() == 1)
        points_S += 2;
    if (hand_S.size() == 2)
        points_S += 1;
    cout << "Cards Dealt Points\n";
    cout << "Clubs ";
    for (char c : hand_C)
        cout << c << ' ';
    cout << '\n'
         << points_C << '\n';
    cout << "Diamonds ";
    for (char c : hand_D)
        cout << c << ' ';
    cout << '\n'
         << points_D << '\n';
    cout << "Hearts ";
    for (char c : hand_H)
        cout << c << ' ';
    cout << '\n'
         << points_H << '\n';
    cout << "Spades ";
    for (char c : hand_S)
        cout << c << ' ';
    cout << '\n'
         << points_S << '\n';
    cout << "Total " << points_C + points_D + points_H + points_S;
    return 0;
}
