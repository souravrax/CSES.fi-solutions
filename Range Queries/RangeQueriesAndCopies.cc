#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long val;
    Node* left;
    Node* right;
    Node(): left(nullptr), right(nullptr) {}
    Node(long long _val): val(_val), left(nullptr), right(nullptr) {}
};

Node* build(long long l, long long r, vector<long long>& a) {
    if (l == r) return new Node(a[l]);
    long long mid = l + (r - l) / 2;
    auto node = new Node();
    node->right = build(mid + 1, r, a);
    node->left = build(l, mid, a);
    node->val = node->left->val + node->right->val;
    return node;
}

Node* update(long long l, long long r, long long idx, long long val, Node* node) {
    if (l == r) {
        return new Node(val);
    }
    long long mid = l + (r - l) / 2;
    auto new_node = new Node();
    if (idx <= mid) {
        new_node->right = node->right;
        new_node->left = update(l, mid, idx, val, node->left);
    } else {
        new_node->left = node->left;
        new_node->right = update(mid + 1, r, idx, val, node->right);
    }
    new_node->val = new_node->left->val + new_node->right->val;
    return new_node;
}

long long sum(long long l, long long r, long long ql, long long qr, Node* node) {
    if (r < ql || l > qr) return 0;
    if (l >= ql && r <= qr) return node->val;
    long long mid = l + (r - l) / 2;
    return sum(l, mid, ql, qr, node->left) + sum(mid + 1, r, ql, qr, node->right);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long& i : a) cin >> i;
    vector<Node*> copies;
    copies.push_back(build(0, n - 1, a));
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long k, idx, val;
            cin >> k >> idx >> val;
            --k, --idx;
            copies[k] = update(0, n - 1, idx, val, copies[k]);
        } else if (type == 2) {
            long long k, l, r;
            cin >> k >> l >> r;
            --k, --l, --r;
            cout << sum(0, n - 1, l, r, copies[k]) << '\n';
        } else if (type == 3) {
            long long k;
            cin >> k;
            --k;
            copies.push_back(copies[k]);
        }
    }
}