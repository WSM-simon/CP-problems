#include <iostream>
using namespace std;

int main(){
    int n=0, bid=0, bidh=0;
    string namei, namef;
    
    cin >> n;
    for (int i=0; i < n; i++){
        cin >> namei;
        cin >> bidh;
        if (bidh>bid){
            bid = bidh;
            namef = namei;
        }
    }
    cout << namef;
    return 0;
}