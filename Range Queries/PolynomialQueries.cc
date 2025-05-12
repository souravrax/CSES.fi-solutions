/**
 *  author: souravrax
 *  created: 18.07.2021 19:54:20
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

template <typename T> 
struct BIT {
    vector<T> bit;
    int n;
    BIT(int _n) : n(_n) { bit.assign(_n + 1, 0); }
    inline void upd(int x, T val) {
        for (x++; x <= n; x += (x & -x))
            bit[x] += val;
    }
    inline int qry(int x) {
        T ans = 0;
        for (x++; x > 0; x -= (x & -x))
            ans += bit[x];
        return ans;
    }
    inline int qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }
};

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    BIT<ll> bit(n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        bit.upd(i, x);
        a[i] = x;
    }
    ll size = (ll)sqrt(n);
    vector<ll> blocks(size + 1);
    vector<ll> bad_store(n);
    auto upd = [&](int l, int r) {
        for (int i = l; i <= r;) {
            if (i % size == 0 && i + size - 1 <= r) {
                blocks[i / size] += (i - l + 1);
                for (int j = i; j < i + size; j++) {
                    bad_store[j] += j - l + 1;
                }
                i += size;
            } else {
                // dbg() << show(i) << show(i - l + 1);
                bit.upd(i, i - l + 1);
                // bad_store[i] += i - l + 1;
                i++;
            }
        }
    };


    auto qry = [&](int l, int r) {
        ll ans = 0;
        ll other = 0;
        for (int i = l; i <= r;) {
            if (i % size == 0 && i + size - 1 <= r) {
                dbg() << show(blocks[i/size]) << show(bad_store[i]);
                ll now1 = 0, now2 = 0;
                if (blocks[i/size]) {
                    now1 = size*blocks[i/size] + (size*(size-1)/2);
                }
                for (int j = i; j < i + size; j++) {
                    cerr << bad_store[j] << ' ';
                    now2 += bad_store[j];
                }
                cerr << endl;
                dbg() << show(now1) << show(now2);
                ans += now1;
                other += now2;
                i += size;
            } else {
                i++;
            }
        }
        cerr << endl;
        return ans + bit.qry(l, r);
    };

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            upd(l, r);
            vector<ll> bad;
            for (int i = 0; i < n; i += size) {
                bad.push_back(bad_store[i]);
            }
            dbg() << show(blocks) << show(bad);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << qry(l, r) << '\n';
        }
    }
}
