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
const int mod = 1e9+7;

int32_t main(){
    fast; 
    ll n, sum;
    cin >> n >> sum;
    vector<ll> c(n);
    for(ll& i : c) cin >> i;
    vector<ll> dp(sum + 1, 0);

    dp[0] = 1;
    for(int x=1; x<=sum; x++) {
        for(const ll& i : c) {
            if(i <= x) {
                dp[x] = (dp[x] + dp[x-i]) % mod;
            }
        }
    }
    cout << dp[sum] % mod << '\n';
}


