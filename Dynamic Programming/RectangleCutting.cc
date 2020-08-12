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
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    
    for(int h = 1; h <= a; h++) {
        for(int w = 1; w <= b; w++) {
            if(h == w) {
                dp[h][w] = 0;
            } else {
                dp[h][w] = INT_MAX;
                for(int i=1; i<h; i++) dp[h][w] = min(dp[h][w], dp[h-i][w] + dp[i][w] + 1);
                for(int i=1; i<w; i++) dp[h][w] = min(dp[h][w], dp[h][w-i] + dp[h][i] + 1);
            }
        }
    }
    cout << dp[a][b] << '\n';
}

