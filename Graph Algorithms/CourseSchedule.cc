/**
 *  author: souravrax
 *  created: 28.04.2021 09:55:58
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

const int MAXN = 100'005;
vector<int> graph[MAXN];
int color[MAXN];
vector<int> ans;

bool topo(int node) {
    color[node] = 1;
    for (auto& nei : graph[node]) {
        if (color[nei] == 1) {
            return false;
        }
        if (color[nei] == 2) continue;
        if (!topo(nei)) {
            return false;
        }
    }
    color[node] = 2;
    ans.push_back(node + 1);
    return true;
}

int32_t main() {
    int n, m;
    scanf("%d%d", &n, &m);
    fill(color, color + n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        dbg(a, b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            if (!topo(i)) {
                puts("IMPOSSIBLE");
                return 0;
            }
        }
    }
    for (int& i : ans) {
        printf("%d ", i);
    }
    puts("");
}

