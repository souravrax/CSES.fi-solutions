/**
 *  author: souravrax
 *  created: 28.04.2021 11:43:30
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

const int MAXN = 200005;
const int MAX_LOG = 30;
int dp[MAXN][MAX_LOG];

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int par; cin >> par;
        dp[i][0] = --par;
    }
    for (int j = 1; j < MAX_LOG; j++)
        for (int i = 0; i < n; i++) 
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    while (m--) {
        int u, k; cin >> u >> k;
        --u;
        for (int i = MAX_LOG; ~i; i--) {
            if (k & (1 << i)) {
                u = dp[u][i];
            }
        }
        cout << u + 1 << '\n';
    }
}

