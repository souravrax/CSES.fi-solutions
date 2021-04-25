/**
 *  author: souravrax
 *  created: 25.04.2021 19:34:33
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

vector<ll> prefix;
int n, a, b;
void generate_left(vector<ll>& nums, vector<ll>& left) {
    if (b == 0) return;
    ll sum = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (i - l + 1 > b) sum -= nums[l++];
        if (nums[i] > sum + nums[i]) {
            l = i;
            sum = nums[i];
        } else
            sum += nums[i];
        left[i] = max(left[i], sum);
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> a >> b;
    vector<ll> nums(n);
    for (ll& i : nums) cin >> i;
    prefix.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    b -= a;
    ll ans = LLONG_MIN;
    vector<ll> left(n);
    generate_left(nums, left);
    dbg(left);

    for (int i = 0; i + a <= n; i++) {
        ll L = i - 1 >= 0 ? left[i - 1] : 0;
        ans = max(ans, L + prefix[i + a] - prefix[i]);
    }

    cout << ans << '\n';
}

