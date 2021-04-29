/**
 *  author: souravrax
 *  created: 29.04.2021 16:39:20
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

void topo(int u, stack<int>& order) {
    visited[u] = true;
    for (int& v : graph[u]) {
        if (!visited[v]) {
            topo(v, order);
        }
    }
    order.push(u);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --u, --v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    vector<ll> dist(n, INT_MIN);

    stack<int> order;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dbg(i);
            topo(i, order);
        }
    }
    dist[0] = 1;
    assert(dist[0] == 1);
    while (!order.empty()) {
        int u = order.top(); order.pop();
        if (dist[u] < 0) continue;
        for (auto& v : graph[u]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
            }
        }
    }

    if (dist[n - 1] < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    int u = n - 1;
    ll cnt = dist[n - 1];
    while (cnt--) {
        path.push_back(u + 1);
        if (u == 0) break;
        for (auto& v : rgraph[u]) {
            if (dist[v] == dist[u] - 1) {
                u = v;
                break;
            }
        }
    }
    reverse(all(path));
    cout << dist[n - 1] << '\n';
    for (int& i : path) {
        cout << i << ' ';
    }
    cout << '\n';
}

