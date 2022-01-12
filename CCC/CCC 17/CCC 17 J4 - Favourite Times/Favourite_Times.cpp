#include <iostream>

using namespace std;

int t_add, thou, hun, ten, dig, fav=0, t=1200;

int time_add(int t){
    t++;
    if ((t%100) >= 60) t += 40;
    if (t >= 1300) t -= 1200;

    return t;
}


int main(){
    cin >> t_add;
    for (int i=0; i<t_add%720; i++){
        t = time_add(t);

        if (t<1000){
            hun = t/100; ten = (t%100)/10; dig = t%10;
            if (hun - ten == ten - dig) fav += 1;
        }
        else{
            thou=t/1000; hun=t%1000/100; ten = (t%100)/10; dig = t%10;
            if (thou - hun == hun - ten && hun - ten == ten - dig) fav += 1;
        }
    }
    fav += (t_add/720)*31;
    cout << fav;

    return 0;
}