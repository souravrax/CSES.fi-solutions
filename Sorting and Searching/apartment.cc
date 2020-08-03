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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desired(n);
    vector<int> apartments;
    for(int& i : desired) cin>>i;
    for(int i=0; i<m; i++){
        int e;
        cin>>e;
        apartments.push_back(e);
    }
    sort(all(desired));
    sort(all(apartments));
    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m){
        if(desired[i]+k < apartments[j]) i++;
        else if(desired[i]-k > apartments[j]) j++;
        else{
            i++;
            j++;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}

