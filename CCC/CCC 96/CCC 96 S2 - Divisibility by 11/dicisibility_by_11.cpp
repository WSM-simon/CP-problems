#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    string num;

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> num;

        string num_cpy(num);
        cout << num << '\n';
        for (int j=num.length()-1; j>1; j--){
            short last = num[j]-'0';
            short b_last = num[j-1]-'0';

            num = num.substr(0, j);
            if (last>b_last){
                int diff = last-b_last;
                num[j-1]=(10-diff)+'0';
                num[j-2]-=1;
            }
            else
                num[j-1] -= last;
            cout << num << '\n';
        }
        if (num == "11"){
            cout << "The number " << num_cpy << " is divisible by 11." << '\n' << '\n';
        }
        else{
            cout << "The number " << num_cpy << " is not divisible by 11." << '\n' << '\n';
        }
    }

    return 0;
}