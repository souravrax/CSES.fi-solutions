/**
 *  author: souravrax
 *  created: 25.04.2021 15:21:23
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "[ " << #__VA_ARGS__ << " ]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...) (void)0x30
#endif
using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int& i : nums) cin >> i;
    map<int, int> mp;
    int l = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++) {
        mp[nums[r]]++;
        while (len(mp) > k) {
            if (--mp[nums[l]] == 0) {
                mp.erase(nums[l]);
            }
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';
}

