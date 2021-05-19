/**
 *  author: souravrax
 *  created: 19.05.2021 19:22:50
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
using ll = long long;

// Recommended hash function by neal on CF
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
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int& i : a) cin >> i;
    gp_hash_table<int, int, custom_hash> last_appeared_at;
    vector<int> bit(N + 1);
    auto upd = [&](int x, int val) { for (x++; x <= N; x += (x & -x)) bit[x] += val; };
    auto qry = [&](int x) { int ans = 0; for (x++; x > 0; x -= (x & -x)) { ans += bit[x]; } return ans; };
    gp_hash_table<int, vector<pair<int, int>>, custom_hash> queries;
    for (int i = 0, l, r; i < Q; i++) {
        cin >> l >> r;
        --l, --r;
        assert(l >= 0 && r >= l);
        queries[r].emplace_back(l, i);
    }
    vector<int> ans(Q);
    for (int i = 0; i < N; i++) {
        if (last_appeared_at.find(a[i]) != last_appeared_at.end()) {
            int where = last_appeared_at[a[i]];
            upd(where, -1);
            assert(where >= 0);
        } 
        last_appeared_at[a[i]] = i;
        upd(i, 1);
        for (auto& [l, idx] : queries[i]) {
            int now = qry(i) - qry(l - 1);
            ans[idx] = now;
            dbg(now);
        }
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }
}

