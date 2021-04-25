/**
 *  author: souravrax
 *  created: 25.04.2021 13:38:20
**/

/* 
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
[[maybe_unused]] const int mod = (int)1e9 + 7;

namespace std {
#define ar array
#define len(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()
#define str(x) to_string(x)
//@y_combinator
template <class F>
    struct y_combinator {
        F f;
        template <class... Args>
            decltype(auto) operator()(Args &&... args) const {
                // the lambda should take the first argument as `auto&& recurse` or similar.
                return f(*this, std::forward<Args>(args)...);
            }
    };
template <class F>
    inline y_combinator<std::decay_t<F>> make_y_combinator(F &&f) { return {std::forward<F>(f)}; }

//@Debugger
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

template <typename T> inline void mini(T &a, T b) { a = min(a, b); }
template <typename T> inline void maxi(T &a, T b) { a = max(a, b); }
template <class T>
    class Random {
        inline static T range(T &a, T &b) { return a + rand() % (b - a + 1); }
    };
template <class K, class V>
    using table = __gnu_pbds::gp_hash_table<K, V>;
template <typename K, typename V, typename Comp = std::less<K>>
    using ordered_map = __gnu_pbds::tree<
    K, V, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>>
    using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
[[maybe_unused]] const ld PI = 3.141592653589793238f;
vector<string> split(string& s, char delim = ' ') {
    stringstream ss(s);
    replace_if(all(s), [&](char& c) { return c == delim; }, ' ');
    string token;
    vector<string> splits;
    while (ss >> token) splits.emplace_back(token);
    return splits;
}
}; // namespace std

void go(set<int>& st, bool take) {
    if (st.empty()) return;
    if (st.size() == 1) {
        cout << *st.begin() << '\n';
        return;
    }
    set<int> nst;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (take) {
            cout << *it << ' ';
        } else {
            nst.insert(*it);
        }
        take = !take;
    }
    go(nst, take);
}

void test_case([[maybe_unused]] int test_no) {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    go(st, false);
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int T = 1; 
    for (int test_no = 1; test_no <= T; ++test_no) {
        test_case(test_no);
    }
}

// overflows? index_of_of_bound? integer_overflows? read the problem?

