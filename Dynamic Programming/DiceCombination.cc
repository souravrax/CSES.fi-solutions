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
    int sum;
    cin >> sum;
    vector<int> dp(sum + 1, 0);

    dp[0] = 1;
    for(int x=1; x<=sum; x++) {
        for(int d=1; d<=6; d++) {
            if(d <= x) {
                dp[x] = (dp[x] + dp[x-d]) % mod;
            }
        }
    }
    cout << dp[sum] % mod << '\n';
}

