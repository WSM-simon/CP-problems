#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M, C;

bool ifpossible(int t, int cowT[])
{   
    int waitingCow = cowT[0];
    int firstCowInBus = 0;
    int bus = 1;

    for (int i=1; i<N; i++)
    {
        if (((cowT[i] - waitingCow) > t) || ((i - firstCowInBus + 1) > C))
        {
            waitingCow = cowT[i];
            bus++;
            firstCowInBus = i;
        }
    }
    return (bus <= M);
}


int binary(int cowT[])
{   
    int start=0, end=cowT[N-1], mid;

    do{
        mid = start + (end - start)/2;
        if (ifpossible(mid, cowT))
            end = mid;
        else start = mid;
    }while (start + 1 != end);

    // return tuple<int, int, int> (start, mid, end);
    if (ifpossible(mid, cowT)) return mid;
    else return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> N >> M >> C;
    int cowT[N];

    for (int i=0; i<N; i++)
        cin >> cowT[i];

    sort(cowT, cowT+N);

    // tuple<int, int, int> ans = binary(cowT);
    // int a,b,c;
    // tie(a,b,c) = ans;
    // cout << a << ' ' << b << ' ' << c << '\n';
    cout << binary(cowT);
    return 0;
}