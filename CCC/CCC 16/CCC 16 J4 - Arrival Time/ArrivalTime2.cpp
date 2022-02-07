#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;

int N;
void time_print(int t)
{
    int h = t/60;
    int m = t%60;
    if (h>=24)
        h-=24;
    if (h<=9)
        cout << '0';
    cout << h;
    cout << ':';
    if (m<=9)
        cout << '0';
    cout << m << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t1 = 7 * 60, t2 = 10 * 60, t3 = 15 * 60, t4 = 19 * 60;
    string s;
    cin >> s;

    // convert s to minutes
    int hours = stoi(s.substr(0, 2));
    int minutes = stoi(s.substr(3, 2));
    int t_begin = hours * 60 + minutes;

    // timelast is the time you need regularly, 2 hours
    int timelast = 120;
    while (timelast)
    {
        t_begin += 10;
        if ((t_begin > t1 && t_begin <= t2) || (t_begin > t3 && t_begin <= t4))
            timelast -= 5;
        else
            timelast -= 10;
    }
    time_print(t_begin);
    return 0;
}
