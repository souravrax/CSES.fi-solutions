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
int memo[MAXN];
int n, m;

int dp(int u) {
    int& ans = memo[u];
    if (~ans) return ans;
    ans = INT_MIN;
    if (u == n - 1) {
        return ans = 1;
    }
    for (int& v : graph[u]) {
        ans = max(ans, dp(v) + 1);
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --u, --v;
        graph[u].push_back(v);
    }
    fill(memo, memo + n, -1);
    dp(0);

    if (memo[0] < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    int u = 0;
    int cnt = memo[0];
    while (cnt--) {
        path.push_back(u + 1);
        if (u == n - 1) break;
        for (auto& v : graph[u]) {
            if (memo[v] == memo[u] - 1) {
                u = v;
                break;
            }
        }
    }
    cout << memo[0] << '\n';
    for (int& i : path) {
        cout << i << ' ';
    }
    cout << '\n';
}

