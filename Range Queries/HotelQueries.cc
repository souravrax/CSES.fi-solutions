/**
 *  author: souravrax
 *  created: 06.05.2021 23:15:18
**/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = int(2e5) + 5;
int tree[4 * MAXN];

void build(int l, int r, vector<int>& a, int idx) {
    if (l == r) {
        tree[idx] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, a, idx * 2 + 1);
    build(mid + 1, r, a, idx * 2 + 2);
    tree[idx] = max(tree[idx * 2 + 1], tree[idx * 2 + 2]);
}

void upd(int l, int r, int pos, int val, int idx) {
    if (l == r) {
        tree[idx] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) {
        upd(l, mid, pos, val, idx * 2 + 1);
    } else {
        upd(mid + 1, r, pos, val, idx * 2 + 2);
    }
    tree[idx] = max(tree[idx * 2 + 1], tree[idx * 2 + 2]);
}

int qry(int l, int r, int idx, int val) {
    if (tree[idx] < val) return -1;
    if (l == r) {
        return l;
    }
    int mid = l + (r - l) / 2;
    if (val <= tree[idx * 2 + 1]) {
        return qry(l, mid, idx * 2 + 1, val);
    } else {
        return qry(mid + 1, r, idx * 2 + 2, val);
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    build(0, n - 1, a, 0);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int idx = qry(0, n - 1, 0, x);
        cout << idx + 1 << ' ';
        if (idx != -1) {
            a[idx] -= x;
            upd(0, n - 1, idx, a[idx], 0);
        }
    }
}

