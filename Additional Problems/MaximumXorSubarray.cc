/**
 *  author: souravrax
 *  created: 19.05.2021 00:19:58
**/
#include <bits/stdc++.h>
using namespace std;

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

struct node {
    node* values[2];
};

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    node* root = new node();
    int ans = 0;

    auto get = [&](int x) {
        auto curr = root;
        int res = 0;
        for (int i = 30; ~i; i--) {
            res <<= 1;
            int bit = (x >> i) & 1;
            if (curr->values[bit ^ 1]) {
                res |= (bit ^ 1);
                curr = curr->values[bit ^ 1];
            } else {
                res |= bit;
                curr = curr->values[bit];
            }
        }
        return res ^ x;
    };

    auto insert = [&](int x) {
        auto curr = root;
        for (int i = 30; ~i; i--) {
            int bit = (x >> i) & 1;
            if (!curr->values[bit]) curr->values[bit] = new node();
            curr = curr->values[bit];
        }
    };

    int sum = 0;
    insert(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum ^= x;
        ans = max(ans, get(sum));
        insert(sum);
    }
    cout << ans << '\n';
}
