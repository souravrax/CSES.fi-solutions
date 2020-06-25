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
    int n;
    cin>>n;
    vector<int> wt(n);
    for(int& i : wt) cin>>i;
    ll sum = 0;
    for(auto i : wt) sum+=i;
    ll ans = INT_MAX;
    for(int i=1; i<(1<<n); i++){
        ll taken = 0;
        for(int x=0; x<n; x++){
            if(i&(1<<x)){
                taken+=wt[x];
            }
        }
        ans = min(ans, abs(sum - 2*taken));
    }
    cout<<ans<<'\n';
}

