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
int dp[1001][100001];

int32_t main(){
    fast; 
    int n,x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for(int& i : prices) cin >> i;
    for(int& i : pages) cin >> i;
    memset(dp, 0, sizeof dp);

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=x; j++) {
            if(j == 0 || i == 0) dp[i][j] = 0;
            else if(prices[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j - prices[i-1]] + pages[i-1], dp[i-1][j]);
        }
    }
    cout << dp[n][x] << '\n';
}

