/**
 *  author: souravrax
 *  created: 28.04.2021 10:14:21
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

const int MAXN = 100 * 1000 + 5;
vector<int> graph[MAXN];
int visited[MAXN];
vector<int> ans;

pair<bool, int> dfs(int node) {
    visited[node] = 1;
    for (auto& nei : graph[node]) {
        if (visited[nei] == 2) continue;
        if (visited[nei] == 1) {
            ans.push_back(nei);
            ans.push_back(node);
            return {true, nei};
        }
        auto [ok, res]  = dfs(nei);
        if (ok && res != -1) {
            ans.push_back(node);
            if (res == node) {
                return {ok, -1};
            } else {
                return {ok, res};
            }
        }
        if (ok) {
            return {ok, -1};
        }
    }
    visited[node] = 2;
    return {false, -1};
}

int32_t main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        graph[a].push_back(b);
    }

    fill(visited, visited + n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i).first) break;
        }
    }
    if (ans.empty()) {
        puts("IMPOSSIBLE");
    } else {
        printf("%d\n", ans.size());
        reverse(all(ans));
        for (int& i : ans) {
            printf("%d ", i + 1);
        }
        puts("");
    }
}
