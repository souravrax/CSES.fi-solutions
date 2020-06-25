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

void solve(int n, vector<int>& arr, ll sum){
    sum/=2;
    vector<int> a;
    vector<int> b;
    for(int i=n-1; ~i; i--){
        if((ll)arr[i] <= sum){
            a.push_back(arr[i]);
            sum-=arr[i];
        }
        else
            b.push_back(arr[i]);
    }
    cout<<a.size()<<'\n';
    for(auto i : a) cout<<i<<' ';
    cout<<"\n"<<b.size()<<'\n';
    for(auto i : b) cout<<i<<' ';
    cout<<'\n';
}

int32_t main(){
    fast;
    int n;
    cin>>n;
    vector<int> arr(n);
    iota(all(arr), 1);
    ll sum = (ll)((ll)n*(ll)(n+1))/2;
    if(sum&1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        solve(n, arr, sum);
    }
}

