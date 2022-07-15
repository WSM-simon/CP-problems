#include <bits/stdc++.h>
// #include <experimental/random>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;
const int Max = 1000;
const int Min = 0;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

bool is_vowels(char c) {
    for (char c2 : vowels) {
        if (c == c2)
            return 1;
    }
    return 0;
}

char closest_vowel(char c) {
    int Min = 999999;
    char closest = 'a';
    for (char c2 : vowels) {
        if (abs(c2 - c) < Min) {
            Min = abs(c2 - c);
            closest = c2;
        }
    }
    return closest;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, s2 = "";
    cin >> s;
    for (char c : s) {
        s2 += c;
        if (is_vowels(c))
            continue;
        s2 += closest_vowel(c);
        // special case of z
        if (c == 'z') {
            s2 += 'z';
            continue;
        }
        char c2 = c;
        do { c2++; } while (is_vowels(c2) && c2 < 122);
        s2 += c2;
    }
    cout << s2 << '\n';
    return 0;
}