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

int32_t main(){
    fast; 
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for(int x=1; x<=n; x++) {
        int current = x;
        dp[x] = INT_MAX - 1;
        while(current > 0) {
            int rem = current % 10;
            dp[x] = min(dp[x - rem] + 1, dp[x]);
            current /= 10;
        }
    }
    
    cout << dp[n] << '\n';
}

