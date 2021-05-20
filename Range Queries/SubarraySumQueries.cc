/**
 *  author: souravrax
 *  created: 12.05.2021 17:32:10
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
const int INF = INT_MAX;

vector<int> a;
int n, q;
struct node {
    ll prefix, suffix, max_val, sum;
};
const int MAXN = 200005;
node st[4 * MAXN];

void build(int l, int r, int idx = 0) {
    if (l > r) return;
/* dbg(l, r, idx); */
    if (l == r) {
        st[idx] = node{max(0, a[l]), max(0, a[l]), max(0, a[l]), a[l]};
        return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, idx * 2 + 1);
    build(mid + 1, r, idx * 2 + 2);
    st[idx].prefix = max({st[idx * 2 + 1].prefix, st[idx * 2 + 1].sum + st[idx * 2 + 2].prefix, 0LL});
    st[idx].suffix = max({st[idx * 2 + 2].suffix, st[idx * 2 + 2].sum + st[idx * 2 + 1].suffix, 0LL});
    st[idx].sum = st[idx * 2 + 1].sum + st[idx * 2 + 2].sum;
    st[idx].max_val = max({st[idx * 2 + 1].max_val, st[idx * 2 + 2].max_val, st[idx].prefix, st[idx].suffix, st[idx].sum, 0LL, st[idx * 2 + 1].suffix + st[idx * 2 + 2].prefix});
}

void upd(int l, int r, int pos, int val, int idx = 0) {
    if (l == r) {
        st[idx] = node{max(val, 0), max(0, val), max(0, val), val};
        return;
    }
    int mid = l + (r - l) / 2;
    if (mid >= pos) {
        upd(l, mid, pos, val, idx * 2 + 1);
    } else {
        upd(mid + 1, r, pos, val, idx * 2 + 2);
    }
    st[idx].prefix = max({st[idx * 2 + 1].prefix, st[idx * 2 + 1].sum + st[idx * 2 + 2].prefix, 0LL});
    st[idx].suffix = max({st[idx * 2 + 2].suffix, st[idx * 2 + 2].sum + st[idx * 2 + 1].suffix, 0LL});
    st[idx].sum = st[idx * 2 + 1].sum + st[idx * 2 + 2].sum;
    st[idx].max_val = max({st[idx * 2 + 1].max_val, st[idx * 2 + 2].max_val, st[idx].prefix, st[idx].suffix, st[idx].sum, 0LL, st[idx * 2 + 1].suffix + st[idx * 2 + 2].prefix});
}

/* void print_segtree(int l, int r, int idx) { */
/* dbg(l, r, st[idx].prefix, st[idx].sum, st[idx].suffix, st[idx].max_val); */
/* if (l == r) { */
/* return; */
/* } */
/* int mid = l + (r - l) / 2; */
/* print_segtree(l, mid, idx * 2 + 1); */
/* print_segtree(mid + 1, r, idx * 2 + 2); */
/* } */

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> q;
    a.assign(n, 0);
    for (int& i : a) cin >> i;
    build(0, n - 1, 0);
    while (q--) {
        int pos, val; cin >> pos >> val; --pos;
        upd(0, n - 1, pos, val, 0);
/* print_segtree(0, n - 1, 0); */
        cout << st[0].max_val << '\n';
/* puts(""); */
    }
}

