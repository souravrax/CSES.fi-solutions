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
    int cnt = 0;
    int res = INT_MIN;
    char prev = s[0];
    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == prev){
            cnt++;
        }
        else{
            res = max(res, cnt);
            cnt = 1;
        }
        prev = s[i];
    }
    res = max(res, cnt);
    cout<<res<<'\n';
}

