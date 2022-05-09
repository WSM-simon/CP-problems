#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int pink, green, red, orange, target, ans = 0, minnum = 2147483647;
    cin >> pink >> green >> red >> orange >> target;

    for (int p = 0; p < (target / pink) + 1; ++p)
        for (int g = 0; g < (target / green) + 1; ++g)
            for (int r = 0; r < (target / red) + 1; ++r)
                for (int o = 0; o < (target / orange) + 1; ++o)
                    if (p * pink + g * green + r * red + o * orange == target)
                    {
                        ++ans;
                        int sum = p + g + r + o;
                        minnum = min(minnum, sum);
                        cout << "# of PINK is " << p << " # of GREEN is " << g << " # of RED is " << r << " # of ORANGE is " << o << '\n';
                    }

    cout << "Total combinations is " << ans << ".\n";
    cout << "Minimum number of tickets to print is " << minnum << ".\n";
    return 0;
}
