/**
 *  author: souravrax
 *  created: 20.05.2021 22:30:12
**/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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

template <typename T = int>
class BasicSegtree {
private:
    vector<T> t;
    size_t N;
    void build(const vector<T>& a, size_t& _n) {
        for (size_t i = 0; i < _n; i++) t[i + N] = a[i];
        for (size_t i = N - 1; i > 0; i--) t[i] = max(t[i<<1], t[i<<1|1]);
    }
public:
    BasicSegtree() : N(0) {}
    BasicSegtree(size_t _n) {
        N = 1;
        while (N < _n) N <<= 1;
        t.assign(2 * N, (T)0);
    }
    BasicSegtree(const vector<T>& a) {
        size_t _n = (size_t)a.size();
        N = 1;
        while (N < _n) N <<= 1;
        t.assign(2 * N, (T)0);
        build(a, _n);
    }

    void upd(size_t x, T v) {
        t[x += N] = v;
        for (x >>= 1; x; x >>= 1) t[x] = max(t[x << 1], t[x << 1 | 1]);
    }
    T qry(size_t l, size_t r) {
        return qry(l, r, 0, N - 1, 1);
    }
    T qry(int ql, int qr, int l, int r, int idx) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return t[idx];
        int mid = l + (r - l) / 2;
        return max(qry(ql, qr, l, mid, idx << 1), qry(ql, qr, mid + 1, r, idx << 1 | 1));
    }
};

const int MAXN = 2e5 + 5;
// parent -> stores the parent of node(u)
// depth -> stores the depht of node(u)
// heavy -> stores the next node (which is heavy)
// pos -> stores the positions of the nodes (in flattened array)
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
vector<int> tree[MAXN]; // tree
int vals[MAXN]; // value of each node
int curr_pos;
BasicSegtree<int> segtree;
int N, Q;

int dfs(int u, int p = 0) {
    int sub_size = 1;
    parent[u] = p;
    int max_subtree_size = 0;
    for (int& v : tree[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        int res = dfs(v, u);
        sub_size += res;
        if (res > max_subtree_size) {
            max_subtree_size = res;
            heavy[u] = v;
        }
    }
    return sub_size;
}

void decompose(int u, int _head = 0) {
    head[u] = _head, pos[u] = ++curr_pos;
    if (heavy[u] != -1) 
        decompose(heavy[u], _head);
    for (int v : tree[u]) {
        if (v != parent[u] && v != heavy[u]) {
            decompose(v, v);
        }
    }
}

void init_hld() {
    curr_pos = -1;
    fill(heavy, heavy + N, -1);
    /*
     * the "dfs" function calcualtes the heavy[u], and stores the parent and depth of each node
     */
    dfs(0);
    /*
     * the "decompose" function assigns for each node u, the values head[u] 
     * and pos[u] (which are "head of of the heavy path" and "the position of v on the segment tree")
     */
    decompose(0);
}

int qry_hld(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segtree.qry(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segtree.qry(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

void read_tree() {
    for (int i = 0; i < N; i++) cin >> vals[i];
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v; --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    read_tree();
    init_hld();
    vector<int> a(N);
    for (int i = 0; i < N; i++) a[pos[i]] = vals[i];
    segtree = BasicSegtree<int>(a);
    string ans;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, val; cin >> x >> val;
            segtree.upd(pos[x - 1], val);
        } else {
            int u, v; cin >> u >> v; --u, --v;
            ans += to_string(qry_hld(u, v));
            ans.push_back(' ');
        }
    }
    cout << ans << '\n';
}
