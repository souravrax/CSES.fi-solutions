/**
 *  author: sourav rakshit
 *  created: 24.09.2020 17:30:46
**/

/* #pragma GCC optimize("O3") */
/* #pragma GCC target ("avx2") */
/* #pragma GCC optimize("unroll-loops") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

//@pbds
template<typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree<
    K, V, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;
template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;

//@alias
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

//@Macros
#define ar array
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define str(s) to_string(s)

//@Magic Lambdas
namespace std {
template<class Fun> class rec_result{
Fun fun_;
public:
template<class T>
explicit rec_result(T &&fun): fun_(std::forward<T>(fun)) {}
template<class ...Args>
decltype(auto) operator()(Args &&...args) {
return fun_(std::ref(*this), std::forward<Args>(args)...);}};
template<class Fun>decltype(auto) rec(Fun &&fun) {
return rec_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}} // namespace std

//@Debugger
#ifdef LOCAL
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v)
{ os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) 
{ os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) 
{ return os << '(' << p.first << "," << p.second << ')'; }

void flush_out() { cerr << endl; }
template<typename H, typename... T> void flush_out(H h, T... t) { cerr << ' ' << h << " | "; flush_out(t...); }
#define log(...) cerr << "[ " << #__VA_ARGS__ << " ] :", flush_out(__VA_ARGS__)
#else
#define log(...) (void)0x30
#endif

//@Utilities
template<typename T> inline void mini(T& a, T b) { a = min(a, b); }
template<typename T> inline void maxi(T& a, T b) { a = max(a, b); }
template<class T>class Random{ static T range(T&a, T&b){ return a+rand()%(b-a+1); }};

//*//---------------------------- Globals --------------------------//*//

const int mod = 1e9 + 7;
const ll INF = 1e18;
const int nax = 2000 * 2007;
const ld PI = 4*atan((ld)1);

//*//---------------------------- Code Begins Here --------------------------//*//

inline void tc() {
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    vector<ll> dist(n + 1), p(n + 1);

    int x = -1;
    for(int i = 0; i < n; i++) {
        x = -1;
        for(auto& [a, b, c] : edges) {
            if(dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                x = b;
                p[b] = a;
            }
        }
    }

    if(x == -1) cout << "NO\n";
    else {
        for(ll i = 0; i < n; i++) x = p[x];
        vector<ll> cycle;
        for(ll v = x;; v = p[v]) {
            cycle.push_back(v);
            if(v == x && cycle.size() > 1) break;
        }
        cout << "YES\n";
        reverse(all(cycle));
        for(auto& c : cycle) cout << c << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    for(int _=tt-1;~_;--_){
        tc();
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

/* ============ 😇 NEED HELP? ============ */ 
/* Take a look the the overflows */
/* IndexOutOfBound? Accessing nullptr? */
/* What about some stress testing? */
/* Flood with log or use GDB */
/* ============ NOW SOLVE 👊 ============ */ 

