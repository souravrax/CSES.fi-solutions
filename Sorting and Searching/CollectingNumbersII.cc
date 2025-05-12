/**
 *  author: souravrax
 *  created: 21.05.2021 21:01:18
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

int get_cost(const vector<int>& nums) {
    int n = len(nums);
    vector<int> idx((size_t)n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
         return nums[i] < nums[j];
    });
    int last = 20000005;
    int ans = 0;
    dbg(idx);
    for (int& i : idx) {
        if (i < last) ans++;
        last = i;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int cost = get_cost(a);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; --l, --r;
        if (a[l] > 0 && pos[a[l] - 1] < l) cost++;
        if (a[r] > 0 && pos[a[r] - 1] < r) cost++;
        pos[a[r]] = l;
        pos[a[l]] = r;
        swap(a[l], a[r]);
        if (a[l] > 0 && pos[a[l] - 1] < l) cost--;
        if (a[r] > 0 && pos[a[r] - 1] < r) cost--;
        cout << cost << '\n';
    }
}

