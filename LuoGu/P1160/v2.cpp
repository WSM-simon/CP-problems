#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

class linked_list {
public:
    struct Node {
        int left = 0;
        int right = 0;
    };
    void special_insert(int n, int k, int p) {
        if (p) {
            arr[n].right = arr[k].right;
            arr[arr[k].right].left = n;
            arr[n].left = k;
            arr[k].right = n;
        } else {
            arr[n].left = arr[k].left;
            arr[arr[k].left].right = n;
            arr[n].right = k;
            arr[k].left = n;
        }
    }
    void erase(int n) {
        if (arr[n].left == 0 && arr[n].right == 0)
            return;
        arr[arr[n].left].right = arr[n].right;
        arr[arr[n].right].left = arr[n].left;
        arr[n].right = 0;
        arr[n].left = 0;
    }
    Node *begin() {
        return arr;
    }

private:
    Node arr[MxN];
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    linked_list llist;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        int k, p;
        cin >> k >> p;
        llist.special_insert(i, k, p);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        llist.erase(x);
    }
    auto ptr = llist.begin();
    for (int i = ptr->right; i != 0; i = (ptr + i)->right)
        cout << i << ' ';
    return 0;
}