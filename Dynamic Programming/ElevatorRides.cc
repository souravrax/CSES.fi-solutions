/**
 *  author: souravrax
 *  created: 24.04.2021 09:47:32
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

ll n, x;
vector<ll> nums;
ll dp[1 << 20];
ll weight[1 << 20];

void solve() {
    cin >> n >> x;
    nums.assign(n, 0);
    for (ll& i : nums) cin >> i;
    fill(dp, dp + (1 << 20), INT_MAX);
    fill(weight, weight + (1 << 20), INT_MAX);
    dp[0] = 0;
    weight[0] = 0;
    for (ll mask = 0; mask < (1 << n); mask++) {
        for (ll i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                if (weight[mask] + nums[i] <= dp[mask] * x) {
                    if (dp[mask | (1 << i)] > dp[mask]) {
                        dp[mask | (1 << i)] = dp[mask];
                        weight[mask | (1 << i)] = weight[mask] + nums[i];
                    } else if (dp[mask | (1 << i)] == dp[mask]) {
                        weight[mask | (1 << i)] = min(weight[mask | (1 << i)], weight[mask] + nums[i]);
                    }
                } else {
                    if (dp[mask | (1 << i)] > dp[mask] + 1) {
                        dp[mask | (1 << i)] = dp[mask] + 1;
                        weight[mask | (1 << i)] = dp[mask] * x + nums[i];
                    } else if (dp[mask | (1 << i)] == dp[mask] + 1) {
                        weight[mask | (1 << i)] = min(dp[mask] * x + nums[i], weight[mask | (1 << i)]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    for (int t = 1; t <= tt; t++) {
        solve();
    }
}
