#include <iostream>
#include <string>

using namespace std;

int N, cnt, temp;
string line;

int main(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> line;
        temp = line.length()-1;
        cnt = 1;
        for (int j=0; j<temp; j++){
            if (line[j] == line[j+1]){
                cnt++;
            }
            else{
                cout << cnt << " ";
                cout << line[j] << " ";
                cnt = 1;
            }
        }
        cout << cnt << " " << line.back() << "\n";
    }
}