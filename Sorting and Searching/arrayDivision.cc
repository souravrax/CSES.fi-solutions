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

ll subarrays(const vector<ll>& arr, ll maxval) {
    ll res = 0;
    ll n = arr.size();

    ll sum = 0;
    for(ll i=0; i<n;) {
        sum += arr[i];
        if(sum > maxval) {
            res++;
            sum = 0;
        }
        else i++;
    }
    return res + 1;
}

int32_t main(){
    fast; 
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll l = 0, r = 0;
    for(ll& i : arr) {
        cin >> i;
        l = max(l, i);
        r+=i;
    }
    while(l < r) {
        ll mid = l + (r - l) / 2;
        ll nos = subarrays(arr, mid);
        if(nos <= k) r = mid; // if nos is less, then the sum must be less
        else l = mid + 1; // if nos is high then sum should be higher
    }
    cout << l << '\n';
}

