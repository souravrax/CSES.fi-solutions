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
    int n,x;
    cin>>n>>x;
    vector<int> arr;
    vector<pair<int,int>> indexedArr;
    for(int i=0; i<n; i++){
        int e;
        cin>>e;
        arr.push_back(e);
        indexedArr.push_back({e, i+1});
    }
    sort(all(arr));
    sort(all(indexedArr));
    bool found = false;
    for(int i=0; i<n; i++){
        if(x-arr[i] >= 0){
            auto iter = lower_bound(begin(arr)+i+1, end(arr), x-arr[i]);
            log(indexedArr[i].second);
            if(iter!= arr.end() && *iter == x-arr[i]){
                int foundAt = iter - arr.begin();
                cout<<indexedArr[i].second << " " << indexedArr[foundAt].second <<'\n';
                found = true;
                break;
            }
        }
    }
    if(!found){
        cout<<"IMPOSSIBLE"<<'\n';
    }
}

