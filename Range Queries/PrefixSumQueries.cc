/**
 *  author: souravrax
 *  created: 20.05.2021 12:06:24
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

struct Node {
    ll prefix, sum;
};
Node st[1 << 19];
int base = 1;
int N, Q;

void upd(int idx, ll val) {
    idx += base;
    st[idx] = Node{max<ll>(0, val), val};
    for (idx >>= 1; idx > 0; idx >>= 1) {
        auto left = st[idx << 1];
        auto right = st[idx << 1 | 1];
        st[idx] = Node{max<ll>({left.sum + right.prefix, left.prefix, 0}), left.sum + right.sum};
    }
}

Node qry(int l, int r, int ql, int qr, int idx) {
    if (l > qr || r < ql) return Node{0LL, 0LL};
    if (l >= ql && r <= qr) return st[idx];
    int mid = l + (r - l) / 2;
    auto left = qry(l, mid, ql, qr, idx << 1);
    auto right = qry(mid + 1, r, ql, qr, idx << 1 | 1);
    return Node{max<ll>({left.sum + right.prefix, left.prefix, 0}), left.sum + right.sum};
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    while (base < N) base <<= 1;
    fill(st + base, st + 2 * base, Node{0, 0});
    for (int i = 0; i < N; i++) {
        ll x; cin >> x; 
        st[i + base] = Node{max<ll>(x, 0), x};
    }
    for (int i = base - 1; i; i--) {
        auto left = st[i << 1];
        auto right = st[i << 1 | 1];
        st[i] = Node{max<ll>({left.sum + right.prefix, left.prefix, 0}), left.sum + right.sum};
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u; --k;
            upd(k, u);
        } else {
            int l, r; cin >> l >> r; --l, --r;
            cout << qry(0, base - 1, l, r, 1).prefix << '\n';
        }
    }
}
