#include <bits/stdc++.h>
#define ll long long
#define ar3 array<long long, 3>

using namespace std;

const int MxN = 2e3 + 100;
const int MxM = 1e5 + 3;
const ll INF = 1e18 + 7;

ll N, M, R, C;
char graph[MxN][MxN], randchar[3][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};

void print_all() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << graph[i][j];
        }
        cout << " \n"[N != N - 1];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R >> C;

    // initialization
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            graph[i][j] = randchar[i % 3][j % 3];

    // test whether it is possible
    if (R > N || C > M || R < 0 || C < 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if (N % 2 == 0 && C == M && R % 2 == 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if (M % 2 == 0 && R == N && C % 2 == 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    if (R == N) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < C / 2; ++j) {
                graph[i][j] = 'x';
                graph[i][M - j - 1] = 'x';
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = C / 2; j < M - C / 2; ++j) {
                graph[i][j] = randchar[i % 3][0];
            }
        }
        if (C % 2 == 1)
            for (int i = 0; i < N; ++i)
                graph[i][M / 2] = 'x';

        print_all();
        return 0;
    }
    if (C == M) {
        for (int i = 0; i < R / 2; ++i) {
            for (int j = 0; j < M; ++j) {
                graph[i][j] = 'x';
                graph[N - i - 1][j] = 'x';
            }
        }
        for (int i = R / 2; i < N - R / 2; ++i) {
            for (int j = 0; j < M; ++j) {
                graph[i][j] = randchar[0][j % 3];
            }
        }
        if (R % 2 == 1)
            for (int j = 0; j < M; ++j)
                graph[N / 2][j] = 'x';

        print_all();
        return 0;
    }
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < M; ++j)
            graph[i][j] = 'x';
    for (int j = 0; j < C; ++j)
        for (int i = 0; i < N; ++i)
            graph[i][j] = 'x';
    print_all();
    return 0;
}
