/**
 *  author: souravrax
 *  created: 18.05.2021 21:10:20
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

const int MAXN = 200005;
int N, M;
vector<int> tree[MAXN];
int fake[MAXN];
int dp[MAXN][20];
int depth[MAXN];
vector<int> ans;

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = 19; ~i; i--) {
        if (diff & (1 << i)) u = dp[u][i];
    }
    if (u == v) return u;
    for (int i = 19; ~i; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

inline void find_depth(int u, int p, int d) { 
    depth[u] = d; 
    dp[u][0] = p;
    for (int& v : tree[u]) { if (v != p) find_depth(v, u, d + 1); }
}

ll dfs(int u, int p) {
    ans[u] = fake[u];
    for (int& v : tree[u]) {
        if (v != p) {
            ans[u] += dfs(v, u);
        }
    }
    return ans[u];
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    fill(fake, fake + N, 0);
    ans.assign(N, 0);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    find_depth(0, 0, 0);

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < N; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; --a, --b;
        int lca = get_lca(a, b);
        dbg(a, b, lca);
        fake[a]++;
        if (lca != 0) {
            fake[dp[lca][0]]--;
        }
        fake[b]++;
        fake[lca]--;
    }
    dfs(0, 0);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
