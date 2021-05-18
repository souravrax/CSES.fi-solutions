/**
 *  author: souravrax
 *  created: 12.05.2021 12:43:38
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


int memo[200005][2];
vector<int> tree[200005];
int N;

int dp(int u, int c, int p) {
    int& ans = memo[u][c];
    if (~ans) return ans;
    ans = 0;

    if (c) {
        // can take, or not take
        vector<int> one, zero;
        int not_take = 0;
        for (int& v : tree[u]) {
            if (v == p) continue;
            one.push_back(dp(v, 1, u));
            not_take += one.back();
            zero.push_back(dp(v, 0, u));
        }
        ans = not_take;
        for (int i = 0; i < len(one); i++) {
            ans = max(ans, zero[i] + not_take - one[i] + 1);
        }
    } else {
        for (int& v : tree[u]) {
            if (v == p) continue;
            ans += max(dp(v, 0, u), dp(v, 1, u));
        }
    }

/* dbg(u, c, ans); */

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    vector<int> indegree(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        indegree[b]++;
    }
    memset(memo, -1, sizeof memo);
    int ans = dp(0, 1, 0);
    cout << ans << '\n';
}

