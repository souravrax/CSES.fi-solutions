// Gives number overflow
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
       int x, y;
       cin>>x>>y;
       ll diag = 1;
       if(x > y){
           diag = x*x - x + 1;
           int diff = abs(x - y);
           if(x&1){
               diag-=diff;
           }
           else diag+=diff;
       }
       else if(y > x){
           diag = y*y - y + 1;
           int diff = abs(x - y);
           if(y&1){
               diag+=diff;
           }
           else{
               diag-=diff;
           }
       }
       else if(x == y){
           diag = y*y - y + 1;
       }
       cout<<diag<<'\n';
    }
}
 