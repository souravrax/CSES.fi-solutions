#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()

#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) 0x30
#endif

using ll = long long;
#define int ll


int32_t main(){
    fast; 
    int n;
    cin>>n;
    vector<int> k(n);
    for(int& i : k) cin>>i;
    int ans = 0;
    int i = 0,j = 0;
    set<int> s;
    while(j<n){
        if(s.count(k[j])){
            ans = max(ans, j-i);
            while(k[i]!=k[j]){
                s.erase(k[i++]);
            }
            i++;
        }
        else s.insert(k[j]);
        j++;
    }
    ans = max(ans, j-i);
    cout<<ans<<'\n';
}

