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
    int x,n;
    cin>>x>>n;
    multiset<int> dist;
    dist.insert(x);
    set<int> position;
    position.insert(0);
    position.insert(x);
    for(int i=0, p; i<n; i++){
        cin>>p;
        position.insert(p);

        auto iter = position.find(p);
        auto pre = prev(iter);
        auto nxt = next(iter);
        int prev_dist = (*nxt) - (*pre);

        log(*pre);
        log(*nxt);

        auto to_be_removed = dist.find(prev_dist);
        if(to_be_removed!=dist.end()){
            dist.erase(to_be_removed);
        }

        dist.insert((*nxt) - (*iter));
        dist.insert((*iter) - (*pre));
        cout<<*prev(dist.end())<<' ';
    }
    cout<<'\n';
}

