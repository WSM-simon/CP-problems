#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e6 + 3;

int N, M, arr[MxN];
// deques only store indexes
deque<int> qMx, qMn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    // solving for Min
    for (int i = 0; i < N; ++i) {
        // out of the window
        if (!qMn.empty() && i - qMn.front() >= M)
            qMn.pop_front();
        // qMx.back() be removed, cause the new coming one is smaller than these old elements
        while (!qMn.empty() && arr[qMn.back()] >= arr[i])
            qMn.pop_back();
        // push back the new element
        qMn.push_back(i);
        if (i >= M - 1)
            cout << arr[qMn.front()] << ' ';
    }
    cout << '\n';
    // solving for Max
    for (int i = 0; i < N; ++i) {
        // out of the window
        if (!qMx.empty() && i - qMx.front() >= M)
            qMx.pop_front();
        // qMx.back() be removed, cause the new coming one is greater than these old elements
        while (!qMx.empty() && arr[qMx.back()] <= arr[i])
            qMx.pop_back();
        // push back the new element
        qMx.push_back(i);
        if (i >= M - 1)
            cout << arr[qMx.front()] << ' ';
    }
    cout << '\n';
    return 0;
}