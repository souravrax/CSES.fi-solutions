/**
 *  author: sourav rakshit
 *  created: 20.09.2020 16:29:59
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


int binpow(ll n, ll p, ll mod) {
    ll res = 1;
    while(p) {
        if(p&1) res = (res * n) % mod;
        n = (n * n) % mod;
        p >>= 1;
    }
    return res;
}

int32_t main() {
    fast; 
    int tt = 1;
    cin>>tt;
    while(tt--) {
        ll n, p, c;
        cin >> n >> p >> c;
        cout << binpow(n, binpow(p, c, 1e9 + 6), 1e9 + 7) << '\n';
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}


