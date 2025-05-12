/**
 *  author: sourav rakshit
 *  created: 25.09.2020 10:45:14
**/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) (void)0x30
#endif

using ll = long long;


vector<int> disc, low;
vector<bool> stk;

int tarjan(int n, const vector<vector<int>>& G, int t) {
    if(stk[n]) return disc[n];
    disc[n] = t;
    low[n] = t;
    stk[n] = true;
    for(const int& i : G[n]) {
        low[n] = min(low[n], tarjan(i, G, t + 1));
    }
    stk[n] = false;
    return low[n];
}

int32_t main() {
    fast; 
    int tt = 1;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        while(m--) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        log(n);
        log(m);
        cerr << "HI" << '\n';
        stk.resize(n + 1);
        disc.resize(n + 1);
        low.resize(n + 1);

        tarjan(1, graph, 0);
        unordered_map<int, vector<int>> v;
        for(int i = 1; i <= n; i++) {
            v[low[i]].push_back(i);
        }
        for(auto& i : v) {
            if(i.second.size() < 2) continue;
            cout << "[";
            for(int& x : i.second) cout << x << ' ' ;
            cout << "]";
            cout << '\n';
        }
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

