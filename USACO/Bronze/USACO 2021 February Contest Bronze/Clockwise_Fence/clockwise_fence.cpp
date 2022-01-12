#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve_line(string line)
{   
    int r=0, l=0;
    string temp;

    for(int i=0; i<line.length()-1; i++)
    {   
        temp=line.substr(i,2);
        if((temp == "NE") || (temp == "ES") || (temp == "SW") || (temp =="WN"))
        {
            r++;
        }
        else if((temp == "EN") || (temp == "SE") || (temp == "WS") || (temp == "NW"))
        {
            l++;
        }
    }

    // cout << "r: " << r << endl;
    // cout << "l: " << l << endl;
    if(r>l)
    {
        return "CW";
    }
    else
    {
        return "CCW";
    }
}

int main()
{
    int N;
    cin >> N;

    vector<string> ans(N);
    string line;

    
    for(int i=0; i<N; i++)
    {   
        cin >> line;
        ans[i] = solve_line(line);
    }
    
    for(int i=0; i<N; i++)
    {
        cout << ans[i] << endl;
    }
    return 0; 
}

