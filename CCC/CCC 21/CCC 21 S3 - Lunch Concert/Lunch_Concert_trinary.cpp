#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;

struct Friend{
    ll pos, domain, sped;
};

bool sort_friends(Friend f1,Friend f2) {return(f1.pos < f2.pos);}

ll sumFtime(ll p, Friend friends[]){
    ll t=0;
    for (ll i=0; i<N; i++){
        Friend f=friends[i];
        if (p<(f.pos-f.domain))
            t += (f.pos-p-f.domain)*f.sped;
        else if (p>(f.pos+f.domain))
            t += (f.pos-p+f.domain)*f.sped;
    }
    return t;
}


ll trinarySearch(Friend friends[]){
    ll sumTime=0;
    ll beg=0, ed=friends[N-1].pos;
    ll p1, p2;
    while (beg<=ed){
        if (beg==ed){
            sumTime = sumFtime(beg, friends);
            break;
        }
        else if (beg+1==ed){
            sumTime = min(sumFtime(beg, friends), sumFtime(ed, friends));
            break;
        }
        else if (beg+2==ed){
            sumTime = min(min(sumFtime(beg, friends), sumFtime(beg+1, friends)), sumFtime(ed, friends));
            break;
        }
        
        p1 = beg + (ed-beg)/3;
        p2 = ed - (ed-beg)/3;
        if (sumFtime(p1, friends) > sumFtime(p2, friends))
            beg = p1;
        else if (sumFtime(p1, friends) < sumFtime(p2, friends))
            ed = p2;
        else{
            beg = p1;
            ed = p2;
        }
    }
    return sumTime;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    Friend friends[N+1];
    for (int i=0; i<N; i++){
        cin >> friends[i].pos >> friends[i].sped >> friends[i].domain;
    }

    sort(friends, friends+N, sort_friends);
    ll ans = trinarySearch(friends);

    cout << ans;
    return 0;
}