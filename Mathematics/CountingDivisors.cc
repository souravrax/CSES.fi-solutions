/**
 *  author: sourav rakshit
 *  created: 20.09.2020 16:50:14
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

const int maxn = 1e6;

int sieve[maxn + 1];

int32_t main() {
    fast; 
    int tt = 1;
    cin>>tt;
    for(int i = 1; i <= maxn; i++) {
        for(int j = i; j <= maxn; j+=i) sieve[j]++;
    }
    while(tt--) {
        int n;
        cin >> n;
        cout << sieve[n] << '\n';
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

