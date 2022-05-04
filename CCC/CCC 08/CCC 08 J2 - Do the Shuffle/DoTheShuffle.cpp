#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
list<char> playlist = {'A', 'B', 'C', 'D', 'E'};

void b1()
{
    char c = playlist.front();
    playlist.pop_front();
    playlist.push_back(c);
}
void b2()
{
    char c = playlist.back();
    playlist.pop_back();
    playlist.push_front(c);
}
void b3()
{
    auto first = playlist.begin();
    auto second = ++playlist.begin();
    swap(*first, *second);
}
void b4()
{
    for (char c:playlist)
        cout << c << ' ';
    cout << '\n';
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> N >> M)
    {
        if (N == 1)
            for (int i=0; i<M; ++i)
                b1();
        if (N == 2)
            for (int i=0; i<M; ++i)
                b2();
        if (N == 3)
            for (int i=0; i<M; ++i)
                b3();
        if (N == 4)
            for (int i=0; i<M; ++i)
                b4();
    }
    return 0;
}
