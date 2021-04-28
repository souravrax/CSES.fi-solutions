/**
 *  author: souravrax
 *  created: 25.04.2021 01:33:15
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
using ll = unsigned long long;

ll memo[20][10][2][2];
string num;

ll dp(int n, int last_digit, bool tight, bool not_started) {
    if (n == 0) return 1;
    ll& ans = memo[n][last_digit][tight][not_started];
    if (~ans) return ans;
    ans = 0;
    if (not_started) {
        ans += dp(n - 1, last_digit, false, true);
    }
    if (tight) {
        int d = num[len(num) - n] - '0';
        for (int c_d = 0; c_d <= d; c_d++) {
            if (last_digit != c_d) {
                ans += dp(n - 1, c_d, d == c_d, false);
            }
        }
    } else {
        for (int c_d = 0; c_d <= 9; c_d++) {
            if (c_d != last_digit) ans += dp(n - 1, c_d, false, false);
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll temp; cin >> temp; temp--;
    num = to_string(temp);
    memset(memo, -1, sizeof memo);
    ll a = temp >= 0 ? dp(len(num), 0, true, true) : 0;

    cin >> num;
    dbg(num);
    memset(memo, -1, sizeof memo);
    ll b = dp(len(num), 0, true, true);
    dbg(b, a);
    cout << (b - a) << '\n';
}

