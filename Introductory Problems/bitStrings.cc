#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) 0x30
#endif

using ll = unsigned long long;
const int mod = 1e9+7;

int binpow(ll a, ll p){
    ll res = 1;
    while(p){
        if(p&1) res = res%mod*a%mod;
        a = a%mod*a%mod;
        p>>=1;
    }
    return res%mod;
}

int32_t main(){
    fast; 
    ll n;
    cin>>n;
    const ll& ans = binpow(2, n);
    cout<<ans<<'\n';
}

