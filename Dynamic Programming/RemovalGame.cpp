#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
    ll sum = 0;
	for(int& i : arr) {
        cin >> i;
        sum+=i;
    }

    vector<vector<ll>> dp(n, vector<ll>(n));
    /* for(int i=n-1; ~i; i--) { */
    /*     for(int j = i; j<n; j++) { */
    /*         if(i == j) dp[i][j] = arr[i]; */
    /*         else dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]); */
    /*     } */
    /* } */

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) dp[i][j] = arr[i];
            else if(i+1 == j) dp[i][j] = max(arr[i], arr[j]);
            else if(i + 2 < n && j - 2 >= 0) dp[i][j] = max(arr[i]+min(dp[i+2][j], dp[i+1][j-1]), arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
        }
    }

    cout << dp[n-1][n-1];
	return 0;
}
