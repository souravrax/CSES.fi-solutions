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
    int tt = 1;
    cin>>tt;
    while(tt--){
        int a,b;
        cin>>a>>b;
        if(a<b)swap(a,b);
        if(a>2*b){
            cout<<"NO\n";
        }else{
            a%=3,b%=3;
            if(a<b)swap(a,b);
            if((a==2 && b==1) || (a==b && b==0)){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}

