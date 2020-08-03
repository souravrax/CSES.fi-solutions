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
    int n, x;
    cin >> n >> x;
    vector<tuple<int,int>> arr(n);
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        arr[i] = {t, i+1};
    }
    sort(all(arr));

    for(int i=0; i<=n-3; i++) {
        auto [a, xx] = arr[i];
        if(a >= x) break;
        for(int j=i+1; j<=n-2; j++) {
            auto [b, yy] = arr[j];
            if(b >= x) break;
            if(a + b >= x) break;
            ll c = x - a - b;
            vector<tuple<int,int>>::iterator it = lower_bound(arr.begin() + j + 1, arr.end(), make_tuple(c, 0));
            if(get<0>(*it) != c) continue;
            cout << xx << ' ' << yy << ' ' << get<1>(*it) << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}


