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

int dp[5001][5001];

int32_t main(){
    fast; 
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    memset(dp, 0, sizeof dp);

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i == 0 && j == 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = min(min(
                        dp[i][j-1], // add
                        dp[i-1][j]), // delete
                        dp[i-1][j-1]) + 1; // replace
            }
            /* cout << dp[i][j] << ' '; */
        }
        /* cout << '\n'; */
    }
    cout << dp[n][m] << '\n';
}

