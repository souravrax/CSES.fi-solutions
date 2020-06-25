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
    unordered_map<char,int> cache;
    for(char i : s){
        cache[i]++;
    }
    string ans;
    stack<char> st;
    for(auto [ch, val] : cache){
        if(val&1){
            st.push(ch);
        }
        if(st.size() == 2){
            cout<<"NO SOLUTION\n";
            return 0;
        }
        for(int i=0; i<val/2; i++){
            ans.push_back(ch);
        }
    }
    string rans = ans;
    reverse(all(rans));
    if(!st.empty())ans.push_back(st.top());
    ans+=rans;
    cout<<ans<<'\n';
}

