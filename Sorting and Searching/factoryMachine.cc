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
    ll n, t;
    cin >> n >> t;
    vector<ll> K(n);
    ll nax = -1e9;
    for(ll& i : K) {
        cin >> i;
        nax = max(nax, i);
    }
    ll timeLowerBound = 0, timeUpperBound = nax * t;
    ll ans = 0;
    while(timeLowerBound <= timeUpperBound) {
        ll currentTime = timeLowerBound + (timeUpperBound - timeLowerBound) / 2;
        ll possible = 0;
        for(ll& i : K) {
            possible+=currentTime/i;
            if(possible >= t) {
                break;
            }
        }

        if(possible >= t) {
            ans = currentTime;
            timeUpperBound = currentTime - 1;
        } else {
            timeLowerBound = currentTime + 1;
        }
    }
    cout << ans << '\n';
}


