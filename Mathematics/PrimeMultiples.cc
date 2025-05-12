/**
 *  author: souravrax
 *  created: 22.06.2021 00:12:27
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename TC, typename T = typename enable_if<!is_same<TC, string>::value, typename TC::value_type>::type> 
ostream& operator<<(ostream &os, const TC &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
struct dbg {
#ifdef LOCAL
    ~dbg() { cerr << endl; }
    template<typename T> dbg& operator<<(const T& args) { cerr << args; return *this; }
#else
    template<typename T> dbg& operator<<(__attribute__((unused))const T& args) { return *this; }
#endif
};
#define show(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (ll& i : a) cin >> i;
    ll ans = 0;

    for (ll& i : a) {
        ans += n / i;
    }

    dbg() << show(ans);
    for (int mask = 0; mask < (1 << k); mask++) {
        ll mul = 1;
        if (__builtin_popcount(mask) == 1) continue;
        for (int i = 0; i < k; i++) {
            if ((mask >> i) & 1) {
                mul *= a[i];
            }
        }
        ans -= n / mul;
    }
    cout << ans << '\n';
}

