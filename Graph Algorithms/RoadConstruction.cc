/**
 *  author: souravrax
 *  created: 29.04.2021 15:57:49
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
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    vector<int> weight(n);
    iota(all(parent), 0);
    fill(all(weight), 1);
    int max_comp = 0;
    function<int(int)> find = [&](int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); };
    auto join = [&](int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (weight[b] > weight[a]) {
            swap(a, b);
        }
        weight[a] += weight[b];
        max_comp = max(max_comp, weight[a]);
        parent[b] = a;
        return true;
    };
    int comp = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        comp -= join(u, v);
        cout << comp << ' ' << max_comp << '\n';
    }
}

