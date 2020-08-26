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
    for(int i=n-1; ~i; i--) {
        for(int j = i; j<n; j++) {
            if(i == j) dp[i][j] = arr[i];
            else dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }

    cout << (sum + dp[0][n-1]) / 2LL << '\n';
	return 0;
}
