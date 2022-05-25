// CCC '03 S2 - Poetry

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;
    int N_move = a - b;
    int B_move = c - d;

    // Nikky move
    int N_dis = (s / (a + b)) * N_move;
    int N_left = s % (a + b);
    // all the left steps will be used on walking forward
    if (N_left <= a)
        N_dis += N_left;
    else
    {
        // walk forward 'a' steps and walk back 'N_left-a' steps
        N_dis += a;
        N_dis -= (N_left - a);
    }

    // Byron move
    int B_dis = (s / (c + d)) * B_move;
    int B_left = s % (c + d);
    // all the left steps will be used on walking forward
    if (B_left <= a)
        B_dis += B_left;
    else
    {
        // walk forward 'c' steps and walk back 'B_left-c' steps
        B_dis += c;
        B_dis -= (B_left - c);
    }

    if (N_dis > B_dis)
        cout << "Nikky\n";
    else if (N_dis<B_dis)
        cout << "Byron\n";
    else
        cout << "Tied\n";
    return 0;
}
