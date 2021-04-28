/**
 *  author: souravrax
 *  created: 25.04.2021 15:33:01
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
    vector<pair<int, int>> intervals(n);
    for (auto& i : intervals) {
        cin >> i.first >> i.second;
    }
    sort(all(intervals), [&](auto& a, auto& b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    });
    multiset<int> ends_at;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ends_at.insert(0);
    }
    for (auto& [s, e] : intervals) {
        auto it = ends_at.upper_bound(s);
        if (it == ends_at.begin()) continue;
        ends_at.erase(prev(it));
        ends_at.insert(e);
        ans++;
    }
    cout << ans << '\n';
}
