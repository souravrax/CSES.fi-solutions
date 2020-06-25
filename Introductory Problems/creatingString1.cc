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
    string s;
    cin>>s;
    sort(all(s));
    set<string> st;
    st.insert(s);
    while(next_permutation(all(s))){
        st.insert(s);
    }
    cout<<st.size()<<'\n';
    for(auto i : st){
        cout<<i<<'\n';
    }
}

