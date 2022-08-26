#include <bits/stdc++.h>
#define ll long long

using namespace std;

class linked_list {
public:
    struct Node {
        int value;
        Node *nxt;
    };
    void insert(int v, Node *p) {
        Node *node = new Node;
        node->value = v;
        node->nxt = p->nxt;
        p->nxt = node;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}