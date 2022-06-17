#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int A = 0, B = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tem;
    while (cin >> tem) {
        if (tem == 1) {
            char c;
            cin >> c;
            int n;
            cin >> n;
            if (c == 'A')
                A = n;
            if (c == 'B')
                B = n;
        }
        if (tem == 2) {
            char c;
            cin >> c;
            if (c == 'A')
                cout << A << '\n';
            if (c == 'B')
                cout << B << '\n';
        }
        if (tem == 3) {
            char c1, c2;
            cin >> c1 >> c2;
            if (c1 == 'A' && c2 == 'B')
                A += B;
            if (c1 == 'B' && c2 == 'A')
                B += A;
            if (c1 == 'A' && c2 == 'A')
                A += A;
            if (c1 == 'B' && c2 == 'B')
                B += B;
        }
        if (tem == 4) {
            char c1, c2;
            cin >> c1 >> c2;
            if (c1 == 'A' && c2 == 'B')
                A *= B;
            if (c1 == 'B' && c2 == 'A')
                B *= A;
            if (c1 == 'A' && c2 == 'A')
                A *= A;
            if (c1 == 'B' && c2 == 'B')
                B *= B;
        }
        if (tem == 5) {
            char c1, c2;
            cin >> c1 >> c2;
            if (c1 == 'A' && c2 == 'B')
                A -= B;
            if (c1 == 'B' && c2 == 'A')
                B -= A;
            if (c1 == 'A' && c2 == 'A')
                A -= A;
            if (c1 == 'B' && c2 == 'B')
                B -= B;
        }
        if (tem == 6) {
            char c1, c2;
            cin >> c1 >> c2;
            if (c1 == 'A' && c2 == 'B')
                A /= B;
            if (c1 == 'B' && c2 == 'A')
                B /= A;
            if (c1 == 'A' && c2 == 'A')
                A /= A;
            if (c1 == 'B' && c2 == 'B')
                B /= B;
        }
        if (tem == 7) {
            return 0;
        }
    }
    return 0;
}