#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
pair<ll, ll> tp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i=0, t1, p1; i<N; i++){
        cin >> t1 >> p1;
        tp[i]=make_pair(t1, p1);
    }
    sort(tp, tp+N);
    double max_sped=0;

    int i=N-1;
    while (i--){
        double speed = abs((double)(tp[i+1].second-tp[i].second)/(tp[i+1].first-tp[i].first));
        if (speed>max_sped) max_sped = speed;
    }

    cout << fixed << setprecision(6) << max_sped;
    return 0;
}