/**
 *  author: souravrax
 *  created: 22.05.2021 15:36:15
**/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (ll)1e9 + 7;

ll fact[1000005];

ll inv(ll a, ll p) {
    if (a == 1) return 1;
    ll ans = 1;
    while (p) {
        if (p&1) ans = ans * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return ans;
}

inline void calc() {
    fact[0] = 1;
    for (ll i = 1; i <= 1000000LL; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    ll mp[26]{};
    calc();
    for (char& c : s) mp[c - 'a']++;
    ll ans = fact[s.size()];
    for (int i = 0; i < 26; i++) {
        ans = (ans * inv(fact[mp[i]], mod - 2)) % mod;
    }
    cout << ans << '\n';
}

