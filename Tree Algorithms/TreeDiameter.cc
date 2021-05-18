/**
 *  author: souravrax
 *  created: 16.05.2021 23:12:32
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

const int MAXN = 3e5 + 2;
vector<int> tree[MAXN];
int ans;

int dp(int node, int par) {
    int max_1 = 0, max_2 = 0;
    for (auto& child : tree[node]) {
        if (child == par) continue;
        int res = dp(child, node);
        if (res > max_1) {
            max_2 = max_1;
            max_1 = res;
        } else if (res > max_2) {
            max_2 = res;
        }
    }
    ans = max(ans, max_1 + max_2 + 1);
    return max_1 + 1;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ans = 0;
    dp(1, -1);
    cout << 3 * (ans - 1) << '\n';
}

