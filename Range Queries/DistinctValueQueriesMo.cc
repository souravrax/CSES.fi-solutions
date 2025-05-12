/**
 *  author: souravrax
 *  created: 07.08.2021 16:53:47
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename TC, typename T = typename enable_if<!is_same<TC, string>::value, typename TC::value_type>::type> 
ostream& operator<<(ostream &os, const TC &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
struct dbg {
#ifdef LOCAL
    ~dbg() { cerr << endl; }
    template<typename T> dbg& operator<<(const T& args) { cerr << args; return *this; }
#else
    template<typename T> dbg& operator<<(__attribute__((unused))const T& args) { return *this; }
#endif
};
#define show(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries[i] = {l, r, i};
    }
    const int B = (int) sqrt(n);
    sort(all(queries), [&](auto& _a, auto& _b) {
        int g1 = get<0>(_a) / B;
        int g2 = get<0>(_b) / B;
        return g1 < g2 || (g1 == g2 && get<1>(_a) < get<1>(_b));
    });
    vector<int> ans(q);

    unordered_map<int, int> mp;
    int lp, rp;

    int cnt = 0;
    auto Add = [&](int x) {
        cnt += mp[x] == 0;
        mp[x]++;
    };

    auto Remove = [&](int x) {
        mp[x]--;
        cnt -= mp[x] == 0;
    };

    lp = rp = get<0>(queries[0]);
    rp--;
    for (auto& [l, r, i] : queries) {
        dbg() << show(l) << show(r) << show(i);

        while (rp < r) Add(a[++rp]);
        while (l < lp) Add(a[--lp]);

        while (lp < l) Remove(a[lp++]);
        while (rp > r) Remove(a[rp--]);

        ans[i] = cnt;
    }
    for (int& i : ans) {
        cout << i << '\n';
    }
}

