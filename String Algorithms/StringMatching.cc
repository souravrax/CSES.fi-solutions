/**
 *  author: souravrax
 *  created: 18.05.2021 18:27:45
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

const int prime = 31;
const ll mod = 1000000000039;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s, p;
    cin >> s >> p;
    int n = len(s);
    int m = len(p);
    vector<ll> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < len(p_pow); i++) {
        p_pow[i] = (p_pow[i - 1] * prime) % mod;
    }
    vector<ll> h(n + 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    ll pattern_hash = 0;
    for (int i = 0; i < m; ++i) {
        pattern_hash = (pattern_hash + (p[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    int ans = 0;
    for (int i = 0; i + m <= n; i++) {
        ll curr_hash = (h[i + m] - h[i]) % mod;
        if (curr_hash == pattern_hash * p_pow[i] % mod) {
            ans++;
        }
    }
    cout << ans << '\n';
}
