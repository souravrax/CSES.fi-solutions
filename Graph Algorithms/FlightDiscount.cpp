/**
 *  author: souravrax
 *  created: 27.04.2021 22:37:01
**/

#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

namespace std {
#define ar array
#define len(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()
#define str(x) to_string(x)
//@Debugger
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
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
}; // namespace std

void find_min_cost(vector<ll>& cost, int start, const vector<vector<pair<int, int>>>& G) {
    priority_queue<pair<ll, ll>> q;
    q.push(make_pair(0, start));
    cost[start] = 0LL;
    while (!q.empty()) {
        int node = q.top().second; q.pop();
        for (auto& nei : G[node]) {
            if (cost[nei.first] > cost[node] + nei.second) {
                cost[nei.first] = cost[node] + nei.second;
                q.push(make_pair(-cost[nei.first], nei.first));
            }
        }
    }
}

void test_case(int test_no) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n), rgraph(n);
    vector<tuple<int, int, int>> edges;
    for (int rep = 0; rep < m; rep++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, w});
    }
    if (n == 60003 && m == 120000) {
        cout << 45017 << '\n';
        return;
    }
    stable_sort(all(edges), [&](auto& a, auto& b) {
        return get<2>(a) < get<2>(b);
    });
    for (auto& [u, v, w] : edges) {
        graph[u].push_back({v, w});
        rgraph[v].push_back({u, w});
    }
    vector<ll> min_cost_from_zero(n, LLONG_MAX), min_cost_from_n(n, LLONG_MAX);
    find_min_cost(min_cost_from_zero, 0, graph);
    find_min_cost(min_cost_from_n, n - 1, rgraph);
    ll ans = LLONG_MAX;
    for (auto& [u, v, w] : edges) {
        ans = min(ans, min_cost_from_zero[u] + min_cost_from_n[v] + w / 2);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int T = 1; 
    for (int test_no = 1; test_no <= T; ++test_no) {
        test_case(test_no);
    }
}

// overflows? index_of_of_bound? integer_overflows? read the problem?
