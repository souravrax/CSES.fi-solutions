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
    int n, x;
    cin>>n>>x;
    vector<int> wt(n);
    for(int& i : wt) cin>>i;
    sort(all(wt));
    int i = 0, j = n-1, cnt = 0;
    while(i < j){
        /* log(wt[i]); */
        /* log(wt[j]); */
        if(wt[i] + wt[j] <= x){
            cnt++;
            i++;
            j--;
        }
        else if(wt[i] > wt[j]){
            i++;
            cnt++;
        }
        else{
            j--;
            cnt++;
        }
    }
    if(i == j) cnt++;
    cout<<cnt<<'\n';
}

