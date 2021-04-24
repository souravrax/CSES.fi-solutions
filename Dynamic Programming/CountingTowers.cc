/**
 *  author: souravrax
 *  created: 23.04.2021 13:43:49
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
const int mod = int(1e9) + 7;

vector<int> blocks;
vector<int> T[20];

void generate(int n, int now) {
    if (n == 0) {
/* cout << bitset<2>(now >> 2) << ' ' << bitset<2>(now & 3) << '\n'; */
        blocks.push_back(now);
        return;
    }
    generate(n - 1, now);
    generate(n - 1, now ^ (1 << (n - 1)));
}

int max_computed = 1;
vector<vector<ll>> dp;

void solve() {
    int n;
    cin >> n;
    for (int i = max_computed + 1; i <= n; i++) {
        for (int j = 0; j < 20; j++) {
            for (auto& p : T[j]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][p]) % mod;
            }
        }
    }
    max_computed = max(max_computed, n);
    ll ans = 0;
    for (int i = 0; i < 16; i++) {
        int _end = blocks[i] & 3;
        if (_end == 3) {
            ans = (ans + dp[n][i]) % mod;
        }
    }
    ans = (ans + dp[n][17]) % mod;
    ans = (ans + dp[n][19]) % mod;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    generate(4, 0);

    for (int i = 0; i < 16; i++) {
        int a = blocks[i] >> 2;
        for (int j = 0; j < 16; j++) {
            int b = blocks[j] & 3;
            if (a == b) {
                T[i].push_back(j);
            }
        }
        if (a == 3) {
            T[i].push_back(17);
            T[i].push_back(19);
        }
    }
    T[16] = T[19] = T[15];
    T[17].push_back(16);
    T[17].push_back(18);
    T[18].push_back(16);
    T[18].push_back(18);

    dp.resize(1000005, vector<ll>(20));
    dp[0][3] = 1;
    max_computed = 0;
    for (int t = 1; t <= tt; t++) {
        solve();
    }
}

