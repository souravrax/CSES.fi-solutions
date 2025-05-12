/**
 *  author: souravrax
 *  created: 28.04.2021 01:13:56
**/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("tune=native")
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
using ll = unsigned long long;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        graph[u].push_back({v, w});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    vector<vector<ll>> cost(n, vector<ll>(k, ULONG_LONG_MAX));
    pq.push({0, 0});
    cost[0][0] = 0;

    while (!pq.empty()) {
        auto [_c, node] = pq.top(); pq.pop();
        ll Max = *max_element(all(cost[node]));
        if (Max < _c) continue;
        for (auto& [nei, w] : graph[node]) {
            auto it = max_element(cost[nei].begin(), cost[nei].end());
            if (*it > _c + w) {
                *it = _c + w;
                pq.push({*it, nei});
            }
        }
    }
    sort(all(cost[n - 1]));
    for (ll& i : cost[n - 1]) cout << i << ' ';
    cout << '\n';
}

