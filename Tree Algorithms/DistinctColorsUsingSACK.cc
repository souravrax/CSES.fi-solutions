/**
 *  author: souravrax
 *  created: 23.05.2021 10:46:34
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

int N;
const int MAXN = 200005;
vector<int> Tree[MAXN];
int val[MAXN];
int ans[MAXN];
using pset = set<int>*;

pset merge(pset a, pset b) {
    if (len(*a) < len(*b)) swap(a, b);
    for (const int& i : *b) {
        a->insert(i);
    }
    return a;
}

pset dfs(int u, int p) {
    pset me = new set<int>();
    me->insert(val[u]);
    for (int& v : Tree[u]) {
        if (v == p) continue;
        pset res = dfs(v, u);
        me = merge(res, me);
    }
    ans[u] = len(*me);
    return me;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    dfs(0, 0);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}


