/**
 *  author: souravrax
 *  created: 28.04.2021 17:41:37
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

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
/* for (int i = 0; i < n; i++) { */
/* puts(bitset<10>(i).to_string().c_str()); */
/* } */
    ll ans = 0;
    n++;
    for (ll i = 1; i < 63; i++) {
        ll val = 1LL << i;
        ans += (val / 2LL) * (n / val);
        ll rem = n % val;
        dbg(rem, val);
        if (rem >= val / 2LL) {
            ans += rem - val / 2;
        }
    }
    cout << ans << '\n';
}

