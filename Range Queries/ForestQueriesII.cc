/**
 *  author: souravrax
 *  created: 21.05.2021 16:55:10
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

template <typename T>
struct FenwickTree2D {
    vector<vector<T>> x;
    FenwickTree2D(int n, int m) : x(n, vector<T>(m)) { }
    void add(int k1, int k2, int a) { // x[k] += a
        for (; k1 < len(x); k1 |= k1 + 1)
            for (int k = k2; k < len(x[k1]); k |= k + 1) x[k1][k] += a;
    }
    T sum(int k1, int k2) { // return x[0] + ... + x[k]
        T s = 0;
        for (; k1 >= 0; k1 = (k1 & (k1 + 1)) - 1)
            for (int k = k2; k >= 0; k = (k & (k + 1)) - 1) s += x[k1][k];
        return s;
    }
};

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    FenwickTree2D<ll> tree(n, n);
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '*') {
                tree.add(i, j, 1);
                matrix[i][j] = 1;
            }
        }
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y; --x, --y;
            tree.add(x, y, matrix[x][y] ? -1 : 1);
            matrix[x][y] ^= 1;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2; --x1, --x2, --y1, --y2;
            ll ans = tree.sum(x2, y2);
            ans -= tree.sum(x1 - 1, y2);
            ans -= tree.sum(x2, y1 - 1);
            ans += tree.sum(x1 - 1, y1 - 1);
            cout << ans << '\n';
        }
    }
}
