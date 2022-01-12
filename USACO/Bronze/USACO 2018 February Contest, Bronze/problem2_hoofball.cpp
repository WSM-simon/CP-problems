#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    // freopen("hoofball.out", "w", stdout);

    int N, next_c, a;
    cin >> N;
    int cows[N];
    map<int, int> cow_num;
    // 3:4 means num 3 will give the ball to num 4

    for (int i=0; i<N; i++)
    {
        cin >> cows[i];
    }
    for (int i=0; i<N-1; i++)
    {
        int cnt[N-i-1];
        for (int j=0; j<N-i-1; j++)
        {
            cnt[j] = abs(cows[i] - cows[i+j+1]);
        }
        a = N-i-1;
        cout << a;
        next_c = min_element(cnt, cnt+a) - cnt;
        cout << next_c;
        cow_num.insert(pair<int, int>(i, next_c+i+1));
    }
}