#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) (void)0x30
#endif

using ll = long long;

int32_t main(){
    fast; 
    int n;
    cin >> n;
    ll sum = 0;
    ll nax = 0;
    for(int i=0; i<n; i++) {
        ll x;
        cin >> x;
        sum+=x;
        nax = max(nax, x);
    }
    cout << max(sum, 2*nax) << '\n';
}

