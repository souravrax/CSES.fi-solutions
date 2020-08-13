#include <bits/stdc++.h>
using namespace std;

#define ar dpay
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) (void)0x30
#endif

using ll = long long;

int dp[200001];

int n2_solve(int n) {
    vector<int> arr(n);
    for(int& i : arr) cin >> i;

    int ans = 1;
    for(int i=0; i<n; i++) {
        dp[i] = 0;
        for(int j=i-1; ~j; j--) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int32_t main(){
    fast; 
    int n;
    cin >> n;
    vector<int> dp(n);
    int len = 0;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.begin() + len, x);

        if(it == dp.begin() + len) {
            dp[len] = x;
            len++;
        }
        else {
            *it = x;
        }
    }
    cout << len << '\n';
}

