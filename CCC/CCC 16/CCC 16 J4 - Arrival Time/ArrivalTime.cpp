#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;

int N;

void time_print(int n)
{

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // these are time points given
    int t1 = 7 * 60, t2 = 10 * 60, t3 = 15 * 60, t4 = 19 * 60;
    string s;
    cin >> s;

    // convert s to minutes
    int hours = stoi(s.substr(0, 2));
    int minutes = stoi(s.substr(3, 2));
    int t_begin = hours*60+minutes;

    // if the begining time is before t1 2 hours
    if (t_begin+120<=t1)
        time_print(t_begin+120);
    // if the t1 - begining time is samller than 3/2 hours = 90 mins, the first rush-hours duration
    // the time cost is t1-begin+(120-(t1-begin))*2 = begin-t1+240 
    else if (t1 - t_begin <= 90)
        time_print(t_begin-t1+240); 
    // if the t1 - begining time is greater than 3/2 hours.
    // the time cost is t1-begin + 2 * 90 + (180 - 90 - (t1-begin))
    //  = 180 + 90 = 270 mins
    else if (t1 - t_begin > 90)
        time_print(270);
    // if the t2 - begin is samller than 120, you need to spend some time after the rush-hours
    // (t2 - begin)*2 + 120 - (t2-begin) = 120 + t2 - begin
    else if (t2-t_begin < 120)
        time_print(120 + t2 - t_begin);
    // the same thing applied for the second rush-hours
    else if (t_begin + 120 <= t3)
        time_print(t_begin+120);
    // note that the second rush-hour duration is 4 hours, that means if you spend the whole 2 hours in it, it doesn't matter.
    // cost (t3 - begin + 2*(120 - (t3-begin))) = begin + 240 - t3
    else if (t3 - t_begin < 120)
        time_print(b+240-t3);
    else if (t_begin - t3 > 0 )
        time_print()
    return 0;
}
