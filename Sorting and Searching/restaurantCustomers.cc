#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) (void)0x30
#endif

using ll = long long;

struct contain{
    int a, int b, int index;
    contain(int a, int b, int index) : a(a), b(b), index(index){};
};

int32_t main(){
    fast; 
    int n;
    vector<contain> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin>>a>>b;
        arr[i] = {a,b,i}; 
    }
    sort(all(arr));
    vector<int> ans(n);
    queue<contain> q;
    int room = 1;
    ans[q.top().index] = room;
    while(!q.empty()){
        contain c = q.front();
        q.pop();
        if(ans[c.index]) continue;
        for(auto i : arr){
            if(i.a > c.b){
                ans[i.index] = room;
                c.b = i.b;
            }
            else{
                q.push(i);
            }
        }
        room++;
    }
    cout<<room-1<<'\n';
    for(auto i : ans){
        cout<<i<<' ' ;
    }
}

