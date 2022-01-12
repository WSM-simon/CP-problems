#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

char solve_line(char line){
    return line;
}

int main(){
    string str1, str2;
    int n;
    char line[100];

    fstream fin;
    fin.open("test.in", ios::in);
    getline(fin, str1);
    
    n = std::stoi(str1);
    for (int i=0; i<n; i++){
        getline(fin, str2);
        ans = solve_line(line);
        cout << ans;
    }
    fin.close();
    return 0; 
}

