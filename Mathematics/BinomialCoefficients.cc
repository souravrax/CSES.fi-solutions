/**
 *  author: souravrax
 *  created: 22.05.2021 15:23:11
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
const ll mod = (int)1e9 + 7;

ll fact[1000001];

void calc() {
    fact[0] = 1;
    for (ll i = 1; i <= 1000000LL; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll inv(ll a, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt; cin >> tt;
    calc();
    while (tt--) {
        ll a, b;
        cin >> a >> b;
        ll a_b = a - b;
        a = fact[a];
        b = fact[b];
        a_b = fact[a_b];
        cout << ((a * inv(b, mod - 2) % mod) * inv(a_b, mod - 2) % mod) << '\n';
    }
}

