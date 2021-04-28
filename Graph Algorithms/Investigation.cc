/**
 *  author: souravrax
 *  created: 28.04.2021 10:57:01
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
const int mod = int(1e9) + 7;
vector<pair<int, int>> graph[MAXN];
map<ll, tuple<ll, ll, ll>> memo;
ll cost[MAXN];
int n, m;

tuple<ll, ll, ll> dp(int node) {
    if (node == n - 1) {
        return {1, 0, 0};
    }
    if (memo.count(node)) {
        return memo[node];
    }
    ll ways = 0;
    ll mn = INT_MAX;
    ll mx = INT_MIN;
    for (auto& [v, w] : graph[node]) {
        if (cost[v] == cost[node] + w) {
            auto [_ways, _mn, _mx] = dp(v);
            ways = (ways + _ways) % mod;
            mn = min(mn, _mn + 1);
            mx = max(mx, _mx + 1);
        }
    }
    return memo[node] = {ways, mn, mx};
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        graph[u].push_back({v, w});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    fill(cost, cost + n, LLONG_MAX);
    q.push({0, 0});
    cost[0] = 0;
    while (!q.empty()) {
        auto [c, u] = q.top(); q.pop();
        if (c > cost[u]) continue;
        for (auto& [v, w] : graph[u]) {
            if (cost[v] > cost[u] + w) {
                cost[v] = cost[u] + w;
                q.push({cost[v], v});
            }
        }
    }
    dbg(vector<int>(cost, cost + n));
    cout << cost[n - 1] << ' ';
    auto [ways, min_route, max_route] = dp(0);
    cout << ways << ' ' << min_route << ' ' << max_route << '\n';
}
