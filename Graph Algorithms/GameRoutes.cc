/**
 *  author: souravrax
 *  created: 28.04.2021 10:45:33
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
int memo[MAXN];
vector<int> graph[MAXN];
const int mod = int(1e9) + 7;

int dp(int u) {
    if (u == 0) {
        return 1;
    }
    int& ans = memo[u];
    if (~ans) return ans;
    ans = 0;
    for (int& v : graph[u]) {
        ans = (ans + dp(v)) % mod;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; cin >> n >> m;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        graph[v].push_back(u);
    }
    int res = dp(n - 1);
    cout << res << '\n';
}

