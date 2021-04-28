/**
 *  author: sourav rakshit
 *  created: 12.01.2021 22:57:36
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr << "[ " << #x << " : " << (x) << " ]\n"
#else
#define log(x) (void)0x30
#endif
using ll = long long;
int main(int argc, char* argv[]) {
    fast; 
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    sort(all(nums));
    int64_t ans = 1;
    for (int i = 0; i < n && ans >= nums[i]; i++) {
        ans += nums[i];
    }
    cout << ans << '\n';
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

