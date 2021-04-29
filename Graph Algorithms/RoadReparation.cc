/**
 *  author: souravrax
 *  created: 29.04.2021 15:47:04
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

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    iota(all(parent), 0);
    function<int(int)> find = [&](int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); };
    auto join = [&](int a, int b) { parent[find(a)] = parent[find(b)]; };
    vector<tuple<int, int, int>> edges(m);
    for (auto& [u, v, w] : edges) cin >> u >> v >> w;
    for (auto& [u, v, w] : edges) --u, --v;
    ll ans = 0;
    sort(all(edges), [&](auto& a, auto& b) {
        return get<2>(a) < get<2>(b);
    });
    for (auto& [u, v, w] : edges) {
        if (find(u) == find(v)) continue;
        ans += w;
        join(u, v);
    }
    int p = find(0);
    for (int i = 0; i < n; i++) {
        parent[i] = find(i);
        if (p != parent[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << ans << '\n';
}

