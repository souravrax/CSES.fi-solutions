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
 
const int M = 501, N = (500 * 501 / 4) + 1;
ll dp[M][N];
const ll mod = ll(1e9) + 7;
const int m_inv = 500000004;

int32_t main(){
    fast; 
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << '\n';
        return 0;
    }

    sum /= 2;
 
    vector<int> arr(n);
    iota(all(arr), 1);
 
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(arr[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]]) % mod;
        }
    }
    cout << (dp[n][sum] * m_inv) % mod << '\n';
}
