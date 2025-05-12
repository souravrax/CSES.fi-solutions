/**
 *  author: souravrax
 *  created: 21.03.2021 23:00:33
**/

// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

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

#ifdef LOCAL
//@Debugger
template <typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        os << '{';
        string sep;
        for (const auto &x : v)
            os << sep << x, sep = ", ";
        return os << '}';
    }
template <typename T, size_t size>
    ostream &operator<<(ostream &os, const array<T, size> &arr) {
        os << '{';
        string sep;
        for (const auto &x : arr)
            os << sep << x, sep = ", ";
        return os << '}';
    }
template <typename A, typename B>
    inline ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << "," << p.second << ')'; }

void flush_out() { cerr << endl; }
template <typename H, typename... T>
    void flush_out(H h, T... t) { cerr << ' ' << h << " | "; flush_out(t...); }
#define log(...) cerr << "[ " << #__VA_ARGS__ << " ] :", flush_out(__VA_ARGS__)
#else
#define log(...) (void)0x30
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
}; // namespace std

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = (int)1e9 + 7;
const ld PI = 3.141592653589793238f;

// overflows? index_of_of_bound? integer_overflows? read the problem?

int n, m;
vector<vector<ll>> graph;
vector<bool> visited;

ll dfs(ll u, ll amount) {
// log(u, amount);
    if (u == n - 1) {
        return amount;
    }
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] > 0 && !visited[v]) {
            ll sent = dfs(v, min(amount, graph[u][v]));
            if (sent > 0) {
                graph[u][v] -= sent;
                graph[v][u] += sent;
                return sent;
            }
        }
    }
    visited[u] = false;
    return 0;
}

void test_case() {
    cin >> n >> m;
    graph.assign(n, vector<ll>(n, 0));
    visited.assign(n, false);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        graph[u][v] += c;
    }
    ll ans = 0;

    ll sent = 0;
    do {
        sent = dfs(0, LLONG_MAX);
        ans += sent;
    } while (sent > 0);

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int T = 1; 
    for (int test_no = 1; test_no <= T; ++test_no) {
        test_case();
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << ld(clock()) / CLOCKS_PER_SEC << "s.\n";
#endif
}

