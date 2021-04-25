/**
 *  author: souravrax
 *  created: 25.04.2021 18:05:25
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
    int n;
    cin >> n;
    vector<array<int, 3>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
        nums[i][2] = i;
    }
    sort(all(nums), [&](auto& a, auto& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    int mx = -2e9;
    vector<int> contained(n), contains(n);
    for (int i = 0; i < n; i++) {
        if (mx >= nums[i][1]) {
            contained[nums[i][2]] = true;
        }
        mx = max(mx, nums[i][1]);
    }
    int mn = 2e9;
    for (int i = n - 1; ~i; i--) {
        if (mn <= nums[i][1]) {
            contains[nums[i][2]] = true;
        }
        mn = min(mn, nums[i][1]);
    }
    for (int& i : contains) cout << i << ' ';
    cout << '\n';
    for (int& i : contained) cout << i << ' ';
    cout << '\n';
}

