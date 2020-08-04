#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) (void)0x30
#endif

using ll = long long;

int32_t main(){
    fast; 
    ll n;
    cin >> n;
    unordered_map<ll, ll> table;
    ll sum = 0;
    table[0]++;

    ll cnt = 0;
    for(ll i=0; i<n; i++) {
        ll x;
        cin >> x;
        sum+=x;
        ll rem = sum % n;
        if(rem < 0) rem+=n;
        auto it = table.find(rem);
        if(it != table.end()) cnt+=it->second;
        table[rem]++;
    }
    cout << cnt << '\n';
}
