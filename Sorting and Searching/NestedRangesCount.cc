/**
 *  author: souravrax
 *  created: 25.04.2021 18:05:25
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

int n;
using table = __gnu_pbds::gp_hash_table<int, int>;

vector<int> get_contains(vector<int>& nums) {
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
        return nums[i] < nums[j] || (nums[i] == nums[j] && i > j);
    });
    vector<int> bit(n + 1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        ans[idx[i]] = 0;
        for (int x = n; x > 0; x -= (x & -x)) ans[idx[i]] += bit[x];
        for (int x = idx[i]; x > 0; x -= (x & -x)) ans[idx[i]] -= bit[x];
        for (int x = idx[i] + 1; x <= n; x += (x & -x)) bit[x] += 1;
    }

    return ans;
}

vector<int> get_contained(vector<int>& nums) {
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
        return nums[i] > nums[j] || (nums[i] == nums[j] && i < j);
    });
    vector<int> bit(n + 1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[idx[i]] = 0;
        for (int x = idx[i] + 1; x > 0; x -= (x & -x)) ans[idx[i]] += bit[x];
        for (int x = idx[i] + 1; x <= n; x += (x & -x)) bit[x] += 1;
    }
    return ans;
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    vector<array<int, 3>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
        nums[i][2] = i;
    }
    sort(all(nums), [&](auto& a, auto& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    vector<int> contained(n), contains(n);

/* for (int i = 0; i < n; i++) { */
/* cout << nums[i][2] << ' '; */
/* } */
/* cout << endl; */

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(nums[i][1]);
    }
    {  // contains calculation
        auto ans = get_contains(arr);
        map<pair<int, int>, int> mx_ok;
        for (int i = 0; i < n; i++) {
            pair<int, int> p = {nums[i][0], nums[i][1]};
            mx_ok[p] = max(mx_ok[p], ans[i]);
        }
        for (int i = 0; i < n; i++) {
            pair<int, int> p = {nums[i][0], nums[i][1]};
            ans[i] = max(ans[i], mx_ok[p]);
            contains[nums[i][2]] = ans[i];
        }
        dbg(ans);
    }
    {  // contained calculation
        auto ans = get_contained(arr);
        map<pair<int, int>, int> mx_ok;
        for (int i = 0; i < n; i++) {
            pair<int, int> p = {nums[i][0], nums[i][1]};
            mx_ok[p] = max(mx_ok[p], ans[i]);
        }
        for (int i = 0; i < n; i++) {
            pair<int, int> p = {nums[i][0], nums[i][1]};
            ans[i] = max(ans[i], mx_ok[p]);
            contained[nums[i][2]] = ans[i];
        }
    }
    dbg(contains);
    dbg(contained);
    for (int& i : contains) cout << i << ' ';
    cout << '\n';
    for (int& i : contained) cout << i << ' ';
    cout << '\n';
}

