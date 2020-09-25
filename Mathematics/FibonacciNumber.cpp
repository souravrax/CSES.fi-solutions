/**
 *  author: sourav rakshit
 *  created: 20.09.2020 18:50:50
**/

/* #pragma GCC optimize("O3") */
/* #pragma GCC target ("avx2") */
/* #pragma GCC optimize("unroll-loops") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") */

#include <bits/stdc++.h>
#undef _GLIBCXX_HAVE_ICONV
#include <bits/extc++.h>
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

void mul(vector<vector<int64_t>>& a, vector<vector<int64_t>> b) {
    /* a[0][0] = ((a[0][0] * b[0][0]) % mod + (a[0][1] * b[1][0]) % mod) % mod; */
    /* a[0][1] = ((a[0][0] * b[0][1]) % mod + (a[0][1] * b[1][1]) % mod) % mod; */

    /* a[1][0] = ((a[1][0] * b[0][0]) % mod + (a[1][1] * b[1][0]) % mod) % mod; */
    /* a[1][1] = ((a[1][0] * b[0][1]) % mod + (a[1][1] * b[1][1]) % mod) % mod; */

    vector<vector<int64_t>> ans(2, vector<int64_t>(2, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    a = ans;
}

inline void tc() {
    int64_t n;
    cin >> n;
    vector<vector<int64_t>> mat = {
        {0, 1},
        {1, 1}
    };
    vector<vector<int64_t>> ans = {
        {1, 0},
        {0, 1}
    };
    while(n) {
        if(n&1) mul(ans, mat);
        mul(mat, mat);
        n >>= 1;
    }

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int tt = 1;
    /* cin >> tt; */
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

