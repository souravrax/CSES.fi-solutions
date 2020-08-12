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

int dp[100002][101];


int32_t main(){
    fast;
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int& i : x) cin >> i;
    memset(dp, 0, sizeof dp);

    for(int i=0; i<n; i++) {
        for(int j=1; j<=m; j++) {
            if(i == 0) {
                if(x[i] == 0 || x[i] == j) {
                    dp[i][j] = 1;
                }
                else dp[i][j] = 0;
            }
            else {
                if(x[i] == 0 || x[i] == j) {
                    dp[i][j] = ((dp[i-1][j] + dp[i-1][j-1]) % mod + dp[i-1][j+1]) % mod;
                }
                else dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++) {
        ans = (ans + dp[n-1][i]) % mod;
    }
    cout << ans << '\n';
}
