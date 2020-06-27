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
    vector<ll> arr(n);
    for(ll& i : arr) cin>>i;
    ll best = INT_MIN, sum = 0;
    for(auto i : arr){
        sum = max(sum+i, i);
        best = max(sum, best);
    }
    cout<<best<<'\n';
}

