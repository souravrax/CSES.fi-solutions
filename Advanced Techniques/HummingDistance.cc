/**
 *  author: souravrax
 *  created: 25.05.2021 09:55:32
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
    int n, k;
    cin >> n >> k;
    vector<bitset<30>> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = bitset<30>(s);
    }
    int ans = k;
    for (int b = 0; b < k; b++) {
        vector<bitset<30>> now;
        for (int i = 0; i < n; i++) {
            if (a[i][b]) now.push_back(a[i]);
        }
        sort(all(now), [&](auto& x, auto& y) {
            return x.count() < y.count();
        });
        for (int i = 1; i < len(now); i++) {
            ans = min<int>(ans, (now[0] ^ now[i]).count());
        }
    }
    cout << ans << '\n';
}

