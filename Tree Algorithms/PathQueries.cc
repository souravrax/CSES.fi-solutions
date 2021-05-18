/**
 *  author: souravrax
 *  created: 18.05.2021 14:33:54
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
vector<int> tree[MAXN];
int arrive[MAXN];
int leave[MAXN];
int timer = -1;
int N, Q;

void dfs(int u, int p) {
    arrive[u] = ++timer;
    for (int& v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    leave[u] = ++timer;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    vector<int> arr(N);
    vector<ll> bit(N * 2 + 1);
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, 0);
    function<void(int, int)> upd = [&](int idx, int val) -> void {
        for (idx++; idx <= N * 2; idx += (idx & -idx)) bit[idx] += val;
    };
    function<ll(int)> qry = [&](int idx) -> ll {
        ll res = 0;
        for (idx++; idx > 0; idx -= (idx & -idx)) res += bit[idx];
        return res;
    };
    for (int i = 0; i < N; i++) {
        upd(arrive[i], arr[i]);
        upd(leave[i], -arr[i]);
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, val; cin >> s >> val; --s;
            upd(arrive[s], val - arr[s]);
            upd(leave[s], arr[s] - val);
            arr[s] = val;
        } else {
            int s; cin >> s; --s;
            cout << qry(arrive[s]) << '\n';
        }
    }
}

