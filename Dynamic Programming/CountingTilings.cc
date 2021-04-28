/**
 *  author: souravrax
 *  created: 24.04.2021 15:42:04
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
[[maybe_unused]] const int mod = int(1e9) + 7;

void get_next(int mask, vector<int>& res, int n, int curr) {
    if (n == 0) {
        res.push_back(curr);
        return;
    }
    curr <<= 1;
    if (mask & (1 << (n - 1))) {
        get_next(mask, res, n - 1, curr);
        if (n >= 2 && (mask & (1 << (n - 2)))) {
            curr <<= 1;
            curr |= 3;
            get_next(mask, res, n - 2, curr);
        }
    } else {
        get_next(mask, res, n - 1, curr | 1);
    }
}
int n, m;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    vector<int> dp(1 << n);
    dp[(1 << n) - 1] = 1;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        vector<int> ndp(1 << n);
        cnt = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> next_mask;
            get_next(mask, next_mask, n, 0);
            cnt = max<int>(cnt, next_mask.size());
            for (auto& _next : next_mask) {
                ndp[mask] = (ndp[mask] + dp[_next]) % mod;
            }
        }
        dp = move(ndp);
    }
    dbg(cnt * (1 << n) * m);
    cout << dp[(1 << n) - 1] << '\n';
}

