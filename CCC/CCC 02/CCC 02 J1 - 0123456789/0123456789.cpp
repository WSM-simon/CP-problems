#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if (N == 0)
    {
        cout << " * * *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << " * * * " << '\n';
    }
    if (N == 1)
    {
        cout << "" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "       " << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "" << '\n';
    }
    if (N == 2)
    {
        cout << " * * *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << " * * *" << '\n';
        cout << "*" << '\n';
        cout << "*" << '\n';
        cout << "*" << '\n';
        cout << " * * * " << '\n';
    }
    if (N == 3)
    {
        cout << " * * *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << " * * *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << " * * *" << '\n';
    }
    if (N == 4)
    {
        cout << "" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << " * * *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "" << '\n';
    }
    if (N == 5)
    {
        cout << " * * *" << '\n';
        cout << "*" << '\n';
        cout << "*" << '\n';
        cout << "*" << '\n';
        cout << " * * *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << " * * *" << '\n';
    }
    if (N == 6)
    {
        cout << " * * *" << '\n';
        cout << "*" << '\n';
        cout << "*" << '\n';
        cout << "*" << '\n';
        cout << " * * *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << " * * *" << '\n';
    }
    if (N == 7)
    {
        cout << " * * *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "" << '\n';
    }
    if (N == 8)
    {
        cout << " * * *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << " * * *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << " * * *" << '\n';
    }
    if (N == 9)
    {
        cout << " * * *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << "*     *" << '\n';
        cout << " * * *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << "      *" << '\n';
        cout << " * * *" << '\n';
    }
    return 0;
}
