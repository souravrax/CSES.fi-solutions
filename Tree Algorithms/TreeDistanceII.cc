/**
 *  author: souravrax
 *  created: 18.05.2021 20:03:16
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

const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];
int subtree_size[MAXN];
ll subtree_sum[MAXN];
int N;

void go(int u, int p) {
    for (int& v : tree[u]) {
       if (v == p) continue;
       go(v, u);
       subtree_size[u] += subtree_size[v];
       subtree_sum[u] += subtree_sum[v];
    }
    subtree_sum[u] += subtree_size[u];
    subtree_size[u]++;
}

ll ans[MAXN];

void get_ans(int u, int p, ll left_subtree_sum) {
    // treat parent as left subtree
    dbg(left_subtree_sum, subtree_size[u], subtree_sum[u]);
    int left_subtree_size = N - subtree_size[u];
    left_subtree_sum -= subtree_size[u] + subtree_sum[u];
    ans[u] = left_subtree_size + left_subtree_sum + subtree_sum[u];
    for (int& v : tree[u]) {
        if (v == p) continue;
        get_ans(v, u, ans[u]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; --a, -- b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    go(0, 0);
    ans[0] = subtree_sum[0];
    for (int& v : tree[0]) {
        get_ans(v, 0, ans[0]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

