/**
 *  author: souravrax
 *  created: 14.05.2021 02:06:26
**/

#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
using oset = __gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

const int MAXN = 1e9;
int N, Q;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    oset st;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        st.insert({a[i], i});
    }
    while (Q--) {
        char t; cin >> t;
        if (t == '?') {
            int l, r; cin >> l >> r;
            cout << st.order_of_key(make_pair(r + 1, 0)) - st.order_of_key(make_pair(l, 0)) << '\n';
        } else {
            int k, x; cin >> k >> x; --k;
            st.erase(st.find({a[k], k}));
            a[k] = x;
            st.insert({a[k], k});
        }
    }
}
