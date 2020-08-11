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

int dp[101][1000002];

int32_t main(){
    fast; 
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int& i : coins) cin >> i;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=x; j++) {
            if(j == 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = INT_MAX - 1;
            else if(coins[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
        }
    }
    const int& ans = dp[n][x];
    cout << (ans == INT_MAX - 1 ? -1 : ans) << '\n';
}

