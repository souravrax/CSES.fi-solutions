/**
 *  author: sourav rakshit
 *  created: 19.09.2020 23:56:40
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
#define str(s) to_string(s);

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

//@Useful inlines
template<typename T> inline void mini(T& a, T b) { a = min(a, b); }
template<typename T> inline void maxi(T& a, T b) { a = max(a, b); }
template<typename T> inline int range(T& a, T& b) { return a+rand()%(b-a+1); }

//*//---------------------------- Globals --------------------------//*//

const int mod = 1e9 + 7;
const ll INF = 1e18;
const int nax = 2000 * 2007;
const ld PI = 4*atan((ld)1);

//*//---------------------------- Code Begins Here --------------------------//*//

inline void tc() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<bool>> G(n, vector<bool>(m, false));
    int sx = 0, sy = 0;
    int dx = 0, dy = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char x; cin >> x;
            if(x == 'A') sx = i, sy = j;
            else if(x == 'B') dx = i, dy = j;
            else if(x == '.') G[i][j] = true;
        }
    }

    G[dx][dy] = true;
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    q.push({sx, sy});

    int dir[][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    auto ok = [&](int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    };

    dist[sx][sy] = 0;
    while(!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        for(auto& x : dir) {
            if(ok(i + x[0], j + x[1])) {
                if(!G[i + x[0]][j + x[1]]) continue;
                if(dist[i + x[0]][j + x[1]] > dist[i][j] + 1) {
                    dist[i + x[0]][j + x[1]] = dist[i][j] + 1;
                    q.push({i + x[0], j + x[1]});
                }
            }
        }
    }
    /* for(int i = 0; i < n; i++) { */
    /*     for(int j = 0; j < m; j++) { */
    /*         if(dist[i][j] == INT_MAX) { */
    /*             cout << '$' << ' '; */
    /*             continue; */
    /*         } */
    /*         cout << dist[i][j] << ' '; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
    if(dist[dx][dy] == INT_MAX) {
        cout << "NO\n";
        exit(0);
    }
    cout << "YES\n" << dist[dx][dy] << '\n';
    string way;
    while(dx != sx || dy != sy) {
        for(int i = 0; i < 4; i++) {
            auto x = dir[i];
            if(ok(dx + x[0], dy + x[1])) {
                if(dist[dx + x[0]][dy + x[1]] == dist[dx][dy] - 1) {

                    if(i == 0) way += 'L';
                    else if(i == 1) way += 'R';
                    else if(i == 2) way += 'U';
                    else way += 'D';

                    dx = dx + x[0];
                    dy = dy + x[1];
                    break;
                }
            }
        }
    }
    reverse(all(way));
    cout << way;
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int tt = 1;
    for(int _=tt-1;~_;--_){
        tc();
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

//1. Check for integer overflow, array bounds
//2. Check for the lowest valid/invalid input
//3. Try special cases, set tle

