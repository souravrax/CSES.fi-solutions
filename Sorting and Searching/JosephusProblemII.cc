/**
 *  author: souravrax
 *  created: 21.05.2021 22:09:04
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
    k %= n;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;
    for (int i = 0; i < n; i++) {
        if (k == 0) {
            cout << i + 1 << ' ';
        }
        st.insert(i + 1);
    }
    if (k == 0) {
        return 0;
    }
    vector<int> ans;
    int idx = k;
    while (len(st) >= k) {
        vector<int> now;
        for (; idx < len(st); idx += k) {
            now.push_back(*st.find_by_order(idx));
            idx++;
        }
        idx %= len(st);
        for (int& i : now) {
            st.erase(i);
            ans.push_back(i);
        }
        dbg(now);
    }
    for (int& i : ans) cout << i << ' ';
    for (int i : st) cout << i << ' ';
    cout << '\n';
}

