/**
 *  author: souravrax
 *  created: 24.05.2021 19:37:27
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

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    int n = len(s);
    int pos = 0, max_len = 1;
    for (int i = 0; i < n; i++) {
        for (int l = i - 1, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
            if (r - l + 1 > max_len) {
                max_len = r - l + 1;
                pos = l;
            }
        }
        for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
            if (r - l + 1 > max_len) {
                max_len = r - l + 1;
                pos = l;
            }
        }
    }
    cout << s.substr(pos, max_len) << '\n';
}

