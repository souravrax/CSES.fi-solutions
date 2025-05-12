/**
 *  author: souravrax
 *  created: 24.05.2021 15:38:24
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

struct UnionFind {
    vector<int> parent;
    vector<int> weight;
    int n;
    UnionFind(int _n) : n(_n) {
        parent.assign(_n, 0);
        weight.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    inline int find(int u) { return u == parent[u] ? u : parent[u] = find(parent[u]); } 
    inline void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (weight[a] > weight[b]) {
            swap(a, b);
        }
        parent[a] = b;
        weight[b] += a;
    } 
    inline bool same(int u, int v) { return find(u) == find(v); }
};

const int N = 2e5 + 5;
int n, q;
vector<int> tree[N];
int depth[N];
int up[N][20];

void dfs(int u, int p, int d = 0) {
    depth[u] = d;
    up[u][0] = p;
    for (int& v : tree[u]) {
        if (v != p) {
            dfs(v, p, d + 1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; --x;
        tree[x].push_back(i);
        uf.join(x, i);
    }
    fill(depth, depth + n, -1);
    for (int i = 0; i < n; i++) {
        if (depth[i] == -1) {
            dfs(i, i);
        }
        dbg(depth[i]);
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    auto qry = [&](int u, int v) {
        if (!uf.same(u, v)) return -1;
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int diff = depth[u] = depth[v];
        for (int i = 19; ~i; i--) {
            if (diff&(1<<i)) u = up[u][i];
        }
        if (u == v) {
            return u;
        }
        for (int i = 19; ~i; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };

    while (q--) {
        int x, y; cin >> x >> y; --x, --y;
        int lca = qry(x, y);
        if (lca == -1) {
            cout << -1 << '\n';
        } else {
            cout << depth[x] + depth[y] - 2 * depth[lca] << '\n';
        }
    }
}
