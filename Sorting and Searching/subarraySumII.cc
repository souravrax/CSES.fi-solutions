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
    int n, k;
    cin >> n >> k;
    map<ll, int> sum_ctr;
    ll current_sum = 0;

    sum_ctr[0] = 1;
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current_sum += x;

        auto it = sum_ctr.find(current_sum - k);
        if (it != sum_ctr.end()) cnt += it->second;

        sum_ctr[current_sum] += 1;
    }

    cout << cnt << "\n";
    return 0;
}

