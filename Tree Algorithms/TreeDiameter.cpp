/**
 *  author: sourav rakshit
 *  created: 14.01.2021 12:16:56
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

namespace std
{
#define ar array
#define sz(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()
#define str(x) to_string(x)

    //@y_combinator
    template <class F>
    struct y_combinator
    {
        F f;
        template <class... Args>
        decltype(auto) operator()(Args &&... args) const
        {
            // the lambda should take the first argument as `auto&& recurse` or similar.
            return f(*this, std::forward<Args>(args)...);
        }
    };
    template <class F>
    y_combinator<std::decay_t<F>> make_y_combinator(F &&f)
    {
        return {std::forward<F>(f)};
    }

//@Debugger
#ifdef LOCAL
    template <typename T>
    ostream &operator<<(ostream &os, const vector<T> &v)
    {
        os << '{';
        string sep;
        for (const auto &x : v)
            os << sep << x, sep = ", ";
        return os << '}';
    }
    template <typename T, size_t size>
    ostream &operator<<(ostream &os, const array<T, size> &arr)
    {
        os << '{';
        string sep;
        for (const auto &x : arr)
            os << sep << x, sep = ", ";
        return os << '}';
    }
    template <typename A, typename B>
    ostream &operator<<(ostream &os, const pair<A, B> &p)
    {
        return os << '(' << p.first << "," << p.second << ')';
    }

    void flush_out() { cerr << endl; }
    template <typename H, typename... T>
    void flush_out(H h, T... t)
    {
        cerr << ' ' << h << " | ";
        flush_out(t...);
    }
#define log(...) cerr << "[ " << #__VA_ARGS__ << " ] :", flush_out(__VA_ARGS__)
#else
#define log(...) (void)0x30
#endif

    template <typename T>
    inline void mini(T &a, T b)
    {
        a = min(a, b);
    }
    template <typename T>
    inline void maxi(T &a, T b) { a = max(a, b); }
    template <class T>
    class Random
    {
        static T range(T &a, T &b) { return a + rand() % (b - a + 1); }
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

const int mod = 1e9 + 7;
const ld PI = 3.141592653589793238;

// overflows? index_of_of_bound? integer_overflows? read the problem?

int visited[1000000];
int dfs(int root, int& ans, vector<vector<int>>& graph) {
    visited[root] = true;
    if (graph[root].empty()) {
        return 1;
    }
    int mx = 0;
    int mx2 = 0;
    for (int& i : graph[root]) {
        if (visited[i]) continue;
        int ret = dfs(i, ans, graph);
        if (ret > mx) {
            mx2 = mx;
            mx = ret;
        }
        else if (ret > mx2) {
            mx2 = ret;
        }
    }
    ans = max(ans, mx2 + mx + 1);
    return mx + 1;
}

void test_case(const int &tc) {
    memset(visited, 0, sizeof visited);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    log(graph);
    int ans = 0;
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            root = i;
            break;
        }
    }
    log(root);
    maxi(ans, dfs(root, ans, graph));
    cout << 3 * (ans - 1) << '\n';
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _t = 1;
    for (int _ = _t - 1; ~_; --_)
    {
        test_case(_);
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

