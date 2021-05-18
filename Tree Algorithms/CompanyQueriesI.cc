/**
 *  author: souravrax
 *  created: 18.05.2021 13:41:12
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
int dp[MAXN][20];
int N, Q;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    dp[0][0] = -1;
    for (int i = 1; i < N; i++) {
        int b; cin >> b; --b;
        dp[i][0] = b;
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < N; i++) {
            if (~dp[i][j - 1]) dp[i][j] = dp[dp[i][j - 1]][j - 1];
            else dp[i][j] = -1;
        }
    }
    while (Q--) {
        int e, k;
        cin >> e >> k; --e;
        for (int i = 19; ~i; i--) {
            if (k & (1 << i)) {
                e = dp[e][i];
                if (e == -1) {
                    break;
                }
            }
        }
        cout << (e > -1 ? e + 1 : e) << "\n";
    }
}

