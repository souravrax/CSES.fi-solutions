/**
 *  author: sourav rakshit
 *  created: 20.09.2020 19:53:43
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

int32_t main() {
    fast; 
    int tt = 1;
    cin>>tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        int prods = m + 1;
        int64_t ans = 1;
        for(int i = 1; i <= m; i++) ans = (ans * i) % mod;
        ans = (ans + (
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

