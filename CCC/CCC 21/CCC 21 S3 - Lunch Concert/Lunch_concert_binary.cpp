#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;

struct Friend{
    ll pos, domain, sped;
};

ll sumFtime(ll p, Friend friends[]){
    ll t=0;
    for (ll i=0; i<N; i++){
        Friend f=friends[i];
        t += max(0ll, abs(p - f.pos) - f.domain) * f.sped;
    }
    return t;
}


ll Search(Friend friends[]){
    ll beg=0, ed=0x3f3f3f3f, mid=0;
    ll m=0, l=0, r=0;;
    while (beg<=ed){
        mid = beg + (ed-beg)/2;
        
        m = sumFtime(mid, friends);
        r = sumFtime(mid+1, friends);
        l = sumFtime(mid-1, friends);
        
        if (m<=l && m<=r)
            break;
        
        if (l>m)
            beg = mid+1;
        else
            ed = mid-1;
            
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    Friend friends[N+1];
    for (int i=0; i<N; i++){
        cin >> friends[i].pos >> friends[i].sped >> friends[i].domain;
    }

    ll ans = Search(friends);

    cout << ans;
    return 0;
}