/**
 *  author: souravrax
 *  created: 14.05.2021 10:50:53
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "[ " << #__VA_ARGS__ << " ]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...) (void)0x30
#endif
using ll = long long;

struct node {
    ll val, lz1, lz2;
    node(ll _val = 0, ll _lz1 = 0, ll _lz2 = 0) : val(_val), lz1(_lz1), lz2(_lz2) {}
};

const int MAXN = 200005;
node tree[2 * MAXN];
int n;
vector<int> a;

// val -> value of the node
// lz1 -> lazy value for the increment operation
// lz2 -> lazy value for the set operation

void build(int l, int r, int k) {
    if (l == r) {
        tree[k] = node(a[l]);
        return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
}

void push(int l, int mid, int r, int k) {
}

ll qry(int l, int r, int k, int lx, int rx) {
    if (l > rx || r < lx) return 0;
    if (l >= lx && r <= rx) {
        if (tree[k].lz2) {
            tree[k].val = (r - l + 1) * tree[k].lz2;
        }
        if (tree[k].lz1) {
            tree[k].val += (r - l + 1) * tree[k].lz1;
        }
        return tree[k].val;
    }
    int mid = l + (r - l) / 2;
    push(l, mid, r, k);
    return qry(l, mid, k * 2, lx, rx) + qry(mid + 1, r, k * 2 + 1, lx, rx);
}

void upd(int l, int r, int k, int lx, int rx, int val, bool inc) {
    if (r < lx || r > lx) return;
    if (l >= lx && r <= rx) {
        if (inc) {
            tree[k].lz1 += val;
        } else {
            tree[k].lz2 = val;
            tree[k].lz1 = 0;
        }
        return;
    }
    int mid = l + (r - l) / 2;
    upd(l, mid, k * 2, lx, rx, val, inc);
    upd(mid + 1, r, k * 2 + 1, lx, rx, val, inc);
    tree[k].val = tree[k * 2].val + tree[k * 2 + 1].val;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int& i : a) cin >> i;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, x;
            cin >> a >> b >> x; --a, --b;
            upd(0, n - 1, 1, a, b, x, true);
        } else if (t == 2) {
            int a, b, x;
            cin >> a >> b >> x; --a, --b;
            upd(0, n - 1, 1, a, b, x, false);
        } else {
            int a, b;
            cin >> a >> b; --a, --b;
            cout << qry(0, n - 1, 1, a, b) << '\n';
        }
    }
}

