/**
 *  author: sourav rakshit
 *  created: 12.01.2021 23:12:24
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
    vector<pair<int,int>> nums(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.emplace_back(x, i);
    }

    sort(nums.begin(), nums.end());
    int ans = 0;
    int last = 2e9;
    for (int i = 1; i <= n; i++) {
        log(last);
        auto it = lower_bound(all(nums), make_pair(i, -1));
        if (it->second < last) {
            ans++;
        }
        last = it->second;
    }
    cout << ans << '\n';
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

