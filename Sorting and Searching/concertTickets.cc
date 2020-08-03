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
    int n,m;
    cin>>n>>m;
    multiset<int> prices;
    vector<int> pay(m);
    for(int i=0, e; i<n; i++) { cin>>e; prices.insert(e); }
    for(int& i : pay) cin>>i;

    for(auto i : pay){
        auto iter = prices.lower_bound(i);
        if(prices.empty()){
            cout<<-1<<'\n';
            continue;
        }
        if(iter!=prices.end()){
            if(*iter > i && iter == prices.begin()){
                cout<<-1<<'\n';
                continue;
            }
            if(*iter > i) iter = prev(iter);
            cout<<*iter<<'\n';
            prices.erase(iter);
        }
        else{
            iter = prev(iter);
            cout<<*iter<<'\n';
            prices.erase(iter);
        }
    }
}

