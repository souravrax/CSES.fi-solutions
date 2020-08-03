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
    vector<pair<int,int>> interval(n);
    for(auto& i : interval){
        cin>>i.first>>i.second;
    }
    sort(all(interval), [&](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
            });
    int cnt = 1;
    pair<int,int> selected = interval[0];
    for(int i=1; i<n; i++){
        if(interval[i].first >= selected.second){
            selected.second = max(selected.second, interval[i].second);
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}
