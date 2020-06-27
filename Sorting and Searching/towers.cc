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
#define int ll
#define len(x) (int)(x).size()

int32_t main(){
    fast; 
    int n;
    cin>>n;
    multiset<int> towers;
    for(int i=0, e; i<n; i++){
        cin>>e;
        multiset<int>::iterator it;
        
        if((it = towers.lower_bound(e+1)) == towers.end()){
            towers.insert(e);
        }
        else{
            log(*it);
            towers.erase(it);
            towers.insert(e);
        }
    }
    cout<<len(towers)<<'\n';
}

