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

template<typename T>
class Segtree2D {
private:
    void build_row(const vector<T>& a, vector<T>& tree) {
        for (int i = 0; i < (int)a.size(); i++) {
            tree[i + M] = a[i];
        }
        for (int i = M - 1; i > 0; i--) {
            tree[i] = comp(tree[i<<1], tree[i<<1|1]);
        }
    }
    vector<T> merge(const vector<T>& tree_a, const vector<T>& tree_b) {
        vector<T> merged_tree(2 * M);
        for (int i = 1; i < 2 * M; i++) {
            merged_tree[i] = comp(tree_a[i], tree_b[i]);
        }
        return merged_tree;
    }
    void bulid(vector<vector<T>>& grid) {
        for (int i = 0; i < (int)grid.size(); i++) {
            build_row(grid[i], root_tree[i + N]);
        }
        for (int i = N - 1; i > 0; i--) {
            root_tree[i] = merge(root_tree[i<<1], root_tree[i<<1|1]);
        }
    }

    void upd_row(int idx, T val, vector<T>& tree) {
        idx += M;
        tree[idx] = val;
        for (idx>>=1; idx > 0; idx>>=1) {
            tree[idx] = comp(tree[idx<<1], tree[idx<<1|1]);
        }
    }

    T qry_row(int l, int r, int lx, int rx, int idx, const vector<T>& tree) {
        if (r < lx || l > rx) return default_value;
        if (l >= lx && r <= rx) return tree[idx];
        int mid = l + (r - l) / 2;
        return comp(qry_row(l, mid, lx, rx, idx<<1, tree), qry_row(mid + 1, r, lx, rx, idx<<1|1, tree));
    }

    T qry_main(int l, int r, int lx, int rx, int ly, int ry, int idx) {
        if (r < lx || l > rx) return default_value;
        if (l >= lx && r <= rx) return qry_row(0, M - 1, ly, ry, 1, root_tree[idx]);
        int mid = l + (r - l) / 2;
        return comp(qry_main(l, mid, lx, rx, ly, ry, idx<<1), qry_main(mid + 1, r, lx, rx, ly, ry, idx<<1|1));
    }
    inline T comp(const T& a, const T& b) {
        return a + b;
    };
public:
    Segtree2D(vector<vector<T>>& grid, T _default_value = 0) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        N = M = 1;
        while (N < n) N <<= 1;
        while (M < m) M <<= 1;
        default_value = _default_value;
        root_tree.assign(2 * N, vector<T>(2 * M, default_value));
        bulid(grid);
    }
    T qry(int x1, int y1, int x2, int y2) {
        return qry_main(0, N - 1, x1, x2, y1, y2, 1);
    }
    void upd(int x, int y, T val) {
        x += N;
        upd_row(y, val, root_tree[x]);
        for (x >>= 1; x > 0; x>>=1) {
            auto& left = root_tree[x<<1];
            auto& right = root_tree[x<<1|1];
            for (int idx = y + M; idx > 0; idx >>= 1) {
                root_tree[x][idx] = comp(left[idx], right[idx]);
            }
        }
    }
private:
    int N, M;
    vector<vector<T>> root_tree;
    T default_value;
};

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector matrix(n, vector(n, 0LL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '*') {
                matrix[i][j] = 1LL;
            }
        }
    }
    Segtree2D<ll> tree(matrix, 0);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y; --x, --y;
            tree.upd(x, y, matrix[x][y] ^ 1);
            matrix[x][y] ^= 1;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2; --x1, --x2, --y1, --y2;
            cout << tree.qry(x1, y1, x2, y2) << '\n';
        }
    }
}
