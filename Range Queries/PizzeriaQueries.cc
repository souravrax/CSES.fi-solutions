/**
 *  author: souravrax
 *  created: 20.05.2021 16:30:10
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

int left_st[1 << 19], right_st[1 << 19];
int N, Q;
int base = 1;

inline void build() {
    for (int i = base - 1; i; i--) {
        left_st[i] = min(left_st[i << 1], left_st[i << 1 | 1]);
        right_st[i] = min(right_st[i << 1], right_st[i << 1 | 1]);
    }
}

inline void upd(int idx, int val) {
    left_st[idx + base] = val + (base - idx - 1);
    right_st[idx + base] = val + idx;
    dbg(left_st[idx], right_st[idx]);
    for (idx = (idx + base) >> 1; idx > 0; idx >>= 1) {
        left_st[idx] = min(left_st[idx << 1], left_st[idx << 1 | 1]);
        right_st[idx] = min(right_st[idx << 1], right_st[idx << 1 | 1]);
    }
}

inline int qry(int ql, int qr, bool is_left, int l = 0, int r = base - 1, int idx = 1) {
    if (l > qr || r < ql) return INT_MAX;
    if (l >= ql && r <= qr) return is_left ? left_st[idx] : right_st[idx];
    int mid = l + (r - l) / 2;
    return min(qry(ql, qr, is_left, l, mid, idx << 1), qry(ql, qr, is_left, mid + 1, r, idx << 1 | 1));
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    while (base < N) base <<= 1;
    fill(left_st + base, left_st + base * 2, INT_MAX);
    fill(right_st + base, right_st + base * 2, INT_MAX);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        left_st[base + i] = x + (base - i - 1);
        right_st[base + i] = x + i;
    }

    build();

    for (int i = 1; i < 2 * base; i++) 
        dbg(i, right_st[i], left_st[i]);

    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, x; cin >> k >> x; --k;
            upd(k, x);
        } else {
            int k; cin >> k; --k;
            int _left = qry(0, k, true) - (base - k - 1);
            int _right = qry(k, N - 1, false) - k;
            cout << min(_left, _right) << '\n';
        }
    }
}

