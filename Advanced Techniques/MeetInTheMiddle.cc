/**
 *  author: souravrax
 *  created: 19.05.2021 00:37:19
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
using ull = unsigned long long;

// Hash function by neal on CF
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ull N, T;
    cin >> N >> T;
    vector<ull> a(N);
    for (ull& i : a) cin >> i;

    if (N == 1) {
        cout << (a[0] == T) << '\n';
        return 0;
    }

    gp_hash_table<ull, ull, custom_hash> mp;
    for (ull mask = 0; mask < (1ULL << (N / 2)); mask++) {
        ull sum = 0;
        for (ull j = 0; j < N / 2; ++j) {
            if ((mask >> j) & 1) {
                sum += a[j];
            }
        }
        mp[sum]++;
    }
    ull ans = 0;
    for (ull mask = 0; mask < (1ULL << (N - N / 2)); mask++) {
        ull sum = 0;
        for (ull j = 0; j < (N - N / 2); ++j) {
            if ((mask >> j) & 1) {
                sum += a[j + N / 2];
            }
        }
        ans += mp[T - sum];
    }
    cout << ans << '\n';
}

