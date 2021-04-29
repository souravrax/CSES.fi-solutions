/**
 *  author: souravrax
 *  created: 29.04.2021 16:25:11
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

const int MAXN = 100005;
vector<int> graph[MAXN];
vector<int> rgraph[MAXN];
bitset<MAXN> visited;

void dfs1(int u, stack<int>& st) {
    visited[u] = true;
    for (auto& v : graph[u]) {
        if (visited[v]) continue;
        dfs1(v, st);
    }
    st.push(u);
}

void dfs2(int u, vector<int>& group) {
    visited[u] = true;
    for (auto& v : rgraph[u]) {
        if (visited[v]) continue;
        dfs2(v, group);
    }
    group.emplace_back(u);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    stack<int> order;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs1(i, order);
    }
    visited.reset();
    int k = 0;
    vector<int> ans(n);
    while (!order.empty()) {
        if (!visited[order.top()]) {
            k++;
            vector<int> curr_group;
            dfs2(order.top(), curr_group);
            dbg(curr_group);
            for (auto& x : curr_group) {
                ans[x] = k;
            }
        }
        order.pop();
    }
    cout << k << '\n';
    for (int& i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

