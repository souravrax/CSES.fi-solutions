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
    long long n;
    cin>>n;
    cout<<n<<' ';
    while(n!=1){
        if(n&1){
            n*=3;
            n++;
        }
        else n/=2;
        cout<<n<<' ';
    }
    cout<<'\n';
}

