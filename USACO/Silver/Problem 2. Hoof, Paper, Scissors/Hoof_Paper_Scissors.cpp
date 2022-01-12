#include <iostream>
#include <fstream>
using namespace std;

void prefix(int h[], int p[], int s[], int N)
{   
    char ges;

    for (int i=1; i<N+1; i++)
    {
        cin >> ges;
        if (ges == 'H')
        {
            h[i] = h[i-1];
            p[i] = p[i-1] + 1;
            s[i] = s[i-1];
        }

        else if (ges == 'P')
        {
            h[i] = h[i-1];
            p[i] = p[i-1];
            s[i] = s[i-1] + 1;
        }

        else if (ges == 'S')
        {
            h[i] = h[i-1] + 1;
            p[i] = p[i-1];
            s[i] = s[i-1];
        }
    } 
}

void judge(int &cnt, int win)
{
    if (win > cnt)
    {
        cnt = win;
    }    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);

    int N, cnt=0, win=0;
    cin >> N;

    int hoof[N+1]={0}, papper[N+1]={0}, scissors[N+1]={0};
    prefix(hoof, papper, scissors, N);


    for (int p=0; p<N+1; p++)
    {   
        win = hoof[p]+scissors[N]-scissors[p];
        judge(cnt, win);
        
        win = hoof[p]+papper[N]-papper[p];
        judge(cnt, win);

        win = scissors[p]+papper[N]-papper[p];
        judge(cnt, win);

        win = scissors[p]+hoof[N]-hoof[p];
        judge(cnt, win);

        win = papper[p]+hoof[N]-hoof[p];
        judge(cnt, win);

        win = papper[p]+scissors[N]-scissors[p];
        judge(cnt, win);
    }
    
    cout << cnt;
}