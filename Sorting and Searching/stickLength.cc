#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) (void)0x30
#endif

using ll = unsigned long long;

int32_t main(){
    fast; 
    ll n;
    cin>>n;
    vector<ll> p(n);
    for(ll& i : p) cin>>i;
    sort(all(p));
    ll median, sum = 0;
    median = p[n/2];
    log(median);
    for(ll& i : p){
        if(i > median){
            sum+=(i-median);
        }
        else sum+=(median - i);
    }
    cout<<sum<<'\n';
}

