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
    string s;
    cin >> s;
    int time = stoi(s);
    int t = time;
    // Ottawa
    cout << time << " in Ottawa\n";
    // Victoria
    t -= 300;
    if (t < 0)
        t += 2400;
    cout << t << " in Victoria\n";
    // Edmonton
    t = time;
    t -= 200;
    if (t < 0)
        t += 2400;
    cout << t << " in Edmonton\n";
    // Winnipeg
    t = time;
    t -= 100;
    if (t < 0)
        t += 2400;
    cout << t << " in Winnipeg\n";
    // Toronto
    cout << time << " in Toronto\n";
    // Halifax
    t = time;
    t += 100;
    if (t >= 2400)
        t -= 2400;
    cout << t << " in Halifax\n";
    // St. John's
    t = time;
    t += 130;
    if (t % 100 >= 60)
    {
        t -= 60;
        t += 100;
    }
    if (t >= 2400)
        t -= 2400;
    cout << t << " in St. John's\n";

    return 0;
}
