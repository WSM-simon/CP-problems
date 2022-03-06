#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>
#define tp3 tuple<pair<int,int>, pair<int, int>, pair<int, int>>

using namespace std;

const int MxN = 3e3+3;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9+7;

struct Tree
{
    pii A,B,C;
};

int N, Q;
vector<Tree> trees;

bool is_in_between(int pt, int trg1, int trg2)
{
    if (trg1>trg2)
        swap(trg1, trg2);
    if (pt>=trg1 && pt <= trg2)
        return 1;
    else
        return 0;
}

bool check(pii pt, Tree tree1)
{
    if (is_in_between(pt.s, tree1.A.s, tree1.B.s) && is_in_between(pt.f, tree1.A.f, tree1.C.f))
    {
        auto f = [](int px, int x1, int x2, int y1, int y2)->int {return (px-y1)(y1-y2);};
    }
}

tp3 find_abc(pii a, pii b, pii c)
{
    if (b.f == a.f && b.s == c.s)
        swap(a, b);
    else if (b.f == c.f && b.s == a.s)
        swap(a, b), swap(b, c);
    else if (c.f == a.f && c.s == b.s)
        swap(a, c), swap(b,c);
    else if (c.f == b.f && c.s == a.s)
        swap(a, c);
    return {a, b, c};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (int i=0; i<N; ++i)
    {
        pii a,b,c;
        cin >> a.f >> a.s;
        cin >> b.f >> b.s;
        cin >> c.f >> c.s;
        tie(a,b,c) = find_abc(a,b,c);
        trees.push_back({a,b,c});
    }
    int cnt=0;
    for (int i=0; i<Q; ++i)
    {
        pii pt;
        cin >> pt.f >> pt.s;
        for (int i=0; i<N; ++i)
        {
            if (check(pt, trees[i]))
                cnt++;
        }
    }
    return 0;
}
