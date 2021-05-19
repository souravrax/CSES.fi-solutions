/**
 *  author: souravrax
 *  created: 18.05.2021 20:40:32
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

const int MAXN = 1e6;
int freq[MAXN + 1];
int arr[MAXN + 1];

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    memset(freq, 0, sizeof freq);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }
    int ans = 1;
    for (int i = 2; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            freq[i] += arr[j];
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        if (freq[i] > 1) {
            ans = i;
        }
    }
    cout << ans << '\n';
}

