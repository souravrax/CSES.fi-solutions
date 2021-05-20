/*
 *  author: souravrax
 *  created: 26.04.2021 11:10:56
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

const int MAXN = 2501;
bitset<MAXN> visited[2];
vector<int> graph[2][MAXN];
ll n, m;

void dfs(int u, int id) {
    visited[id].set(u);
    for (int& v : graph[id][u]) {
        if (!visited[id][v]) {
            dfs(v, id);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges[i] = {a, b, c};
        graph[0][a].push_back(b);
        graph[1][b].push_back(a);
    }

    dfs(0, 0);
    dfs(n - 1, 1);

    bool flag = false;
    vector<ll> cost(n, LLONG_MIN + (ll)2e9);
    cost[0] = 0;
    for (int i = 0; i < n; i++) {
        flag = false;
        for (auto& [u, v, w] : edges) {
            if (visited[0][u] && visited[1][v] && cost[v] < cost[u] + w) {
                cost[v] = cost[u] + w;
                flag = true;
            }
        }
    }
    if (flag) {
        cout << -1 << '\n';
    } else {
        cout << cost[n - 1] << '\n';
    }
}
