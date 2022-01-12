#include <bits/stdc++.h>
using namespace std;

int N;
int grid[101][101]={0};
int fir_col[101]={0};

void print_grid(bool row, bool col){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (row & col) cout << grid[i][j] << ' ';
            else if (row) cout << grid[N-j-1][i] << ' ';
            else if (col) cout << grid[j][N-i-1] << ' ';
            else cout << grid[N-i-1][N-j-1] << ' ';
        }
        cout << '\n';
    }   
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);

    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> grid[i][j];
        }
    }

    for (int i=0; i<N; i++){
        fir_col[i]=grid[i][0];
    }

    bool row = is_sorted(grid[0], grid[0]+N);
    bool col = is_sorted(fir_col, fir_col+N);

    print_grid(row, col);
    return 0;
}