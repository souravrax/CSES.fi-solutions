/**
 *  author: souravrax
 *  created: 29.01.2021 17:17:07
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

#ifdef LOCAL
    //@Debugger
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

struct Point {
    int x, y;
};

int64_t distance(const Point& a, const Point& b) {
    int x = a.x - b.x;
    int y = a.y - b.y;
    return int64_t(x) * x + int64_t(y) * y;
}

inline istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
inline ostream& operator<<(ostream& os, const Point& p) { os << p.x << ' ' << p.y << '\n'; return os; }

const int64_t INF = (int64_t)3e12 + 7;
int64_t solve(const vector<Point>& points) {
    const int n = (int)points.size();
    vector<Point> left, right;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            left.emplace_back(points[i]);
        } else {
            right.push_back(points[i]);
        }
    }
    if (n == 1) return INF;
    if (n == 2) {
        return distance(left.back(), right.back());
    }
    int curr_x = left.back().x;
    int64_t dl = solve(left);
    int64_t dr = solve(right);
    int64_t d = min(dl, dr);
    vector<Point> strips;
    for (auto& point : left) {
        if (abs(point.x - curr_x) < d) {
            strips.push_back(point);
        }
    }
    for (auto& point : right) {
        if (abs(point.x - curr_x) < d) {
            strips.push_back(point);
        }
    }
    sort(strips.begin(), strips.end(), [&](auto& a, auto& b) {
        return a.y < b.y;
    });
    for (int i = 0; i < (int)strips.size(); i++) {
        for (int j = i + 1; j < n && strips[j].y - strips[i].y <= d; j++) {
            d = min(d, distance(strips[i], strips[j]));
        }
    }
    return d;
}

void test_case(const int &test_no) {
    int n; cin >> n;
    vector<Point> points(n); for (Point& p : points) cin >> p;
    int64_t res = solve(points);
    cout << res << '\n';
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
#ifdef LOCAL
    cerr << "\nTime elapsed: " << ld(clock()) / CLOCKS_PER_SEC << "s.\n";
#endif
}

