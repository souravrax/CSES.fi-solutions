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
    ll sum = 0;
    ll res = n*(n+1)/2;
    for(int i=0, num; i<n-1; i++){
        cin>>num;
        sum+=num;
    }
    cout<<res-sum<<'\n'; 
}

