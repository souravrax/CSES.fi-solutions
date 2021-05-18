/**
 *  author: souravrax
 *  created: 18.05.2021 12:04:12
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

const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];
int N;

int get_node() {
    queue<int> q;
    vector<int> dist(N + 1, -1);
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int& v : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return max_element(all(dist)) - dist.begin();
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int edge_node = get_node();
    vector<int> ans(N + 1, INT_MIN);
    for (int rep = 0; rep < 2; rep++) {
        vector<int> dist(N + 1, -1);
        dist[edge_node] = 0;
        queue<int> q;
        q.push(edge_node);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v : tree[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            ans[i] = max(dist[i], ans[i]);
        }
        edge_node = max_element(all(dist)) - dist.begin();
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

