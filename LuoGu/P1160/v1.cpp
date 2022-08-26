// doesn't work

// *****************************************************
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e1 + 3;
const int MxM = 1e5 + 3;

int N, M;

class linked_list {
public:
    struct Node {
        int val = 0;
        Node *left = NULL;
        Node *right = NULL;
    };

    linked_list() {
        for (int i = 0; i < MxN; ++i)
            arr[i].val = i;
        arr[0].right = &arr[1];
        arr[1].left = &arr[0];
    }
    void special_insert(int n, int pos, int lr) {
        if (lr) {
            arr[n].right = arr[pos].right;
            arr[n].left = &arr[pos];
            arr[pos].right->left = &arr[n];
            arr[pos].right = &arr[n];
        } else {
            arr[n].left = arr[pos].left;
            arr[n].right = &arr[pos];
            arr[pos].left->right = &arr[n];
            arr[pos].left = &arr[n];
        }
    }
    void del_node(int n) {
        if (!arr[n].right && !arr[n].left)
            return;
        arr[n].left->right = arr[n].right;
        arr[n].right->left = arr[n].left;
        arr[n].left = NULL;
        arr[n].right = NULL;
    }
    Node *begin() {
        return &arr[0];
    }

private:
    Node arr[MxN];
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // linked list
    linked_list llist;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        int k, p;
        cin >> k >> p;
        llist.special_insert(i, k, p);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int n;
        cin >> n;
        llist.del_node(n);
    }
    for (auto node = llist.begin()->right; node != NULL; node = node->right)
        cout << node->val << ' ';
    return 0;
}