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

const int mod = 1e9 + 7;

int dp[101][1000001];

int32_t main(){
    fast; 
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int& i : c) cin >> i;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=x; j++) {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(c[i-1] > j) dp[i][j] = dp[i-1][j] % mod;
            else dp[i][j] = (dp[i][j-c[i-1]] + dp[i-1][j]) % mod;
        }
    }
    cout << dp[n][x] % mod << '\n';
}

