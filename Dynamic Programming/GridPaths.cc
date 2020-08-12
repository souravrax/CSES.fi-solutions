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

ll dp[1001][1001];

const int mod = 1e9 + 7;

int32_t main(){
    fast; 
    ll n;
    cin >> n;
    vector<string> G(n);
    for(auto& i : G) cin >> i;
    memset(dp, -1, sizeof dp);
    
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            if(G[i][j] == '*') dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i < 0 || j < 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = dp[i][j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[n-1][n-1] << '\n';
}
