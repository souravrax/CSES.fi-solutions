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
    set<int> st;
    for(int i=0, e; i<n; i++){
        cin>>e;
        st.insert(e);
    }
    cout<<st.size()<<'\n';
}

