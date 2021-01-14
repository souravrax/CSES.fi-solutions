/**
 *  author: sourav rakshit
 *  created: 13.01.2021 10:35:54
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

/* const ll mod = 1e9 + 7; */
const ld PI = 3.141592653589793238;

// overflows? index_of_of_bound? integer_overflows? read the problem?

ll lazy[1000007];

void update(ll l, ll r, const ll& rl, const ll& rr, ll idx, const ll& val) {
    if (l > rr || r < rl) return;
    /* log(l, r, rl, rr); */
    if (l == rl && r == rr) {
        lazy[idx] = lazy[idx] + val;
        return;
    }
    ll mid = l + (r - l) / 2;
    update(l, mid, rl, min(rr, mid), idx * 2 + 1, val);
    update(mid + 1, r, max(rl, mid + 1), rr, idx * 2 + 2, val);
}

void build(ll l, ll r, ll idx, const vector<ll>& arr) {
    if (l == r) {
        lazy[idx] = arr[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(l, mid, idx * 2 + 1, arr);
    build(mid + 1, r, idx * 2 + 2, arr);
}

ll query(ll l, ll r, const ll& pos, ll idx) {
    if (l > r) return 0;
    if (l == r) {
        return lazy[idx];
    }
    ll mid = l + (r - l) / 2;
    if (lazy[idx] != 0) {
        lazy[idx * 2 + 1] += lazy[idx];
        lazy[idx * 2 + 2] += lazy[idx];
        lazy[idx] = 0;
    }
    if (pos <= mid) {
        return query(l, mid, pos, idx * 2 + 1);
    }
    return query(mid + 1, r, pos, idx * 2 + 2);
}

void test_case(const int &tc) {
    ll n;
    cin >> n;
    int q;
    cin >> q;
    memset(lazy, 0, sizeof lazy);
    vector<ll> nums(n);
    for (ll& x : nums) cin >> x;
    build(0, n - 1, 0, nums);
    /* log(nums); */
    while (q--) {
        int t; cin >> t;
        /* log(t); */
        if (t == 1) {
            ll a, b, c;
            cin >> a >> b >> c;
            // update
            update(0, n - 1, a - 1, b - 1, 0, c);
        } else {
            ll pos;
            cin >> pos;
            // query
            cout << query(0, n - 1, pos - 1, 0) << '\n';
        }
    }
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

