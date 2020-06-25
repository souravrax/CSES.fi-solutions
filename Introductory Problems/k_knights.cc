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

using ll = long long;

int32_t main(){
    fast; 
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++){
        ll ans = ((i*i)*(i*i - 1)/2)-(4*(i-1)*(i-2));
        cout<<ans<<'\n';
    }
}

