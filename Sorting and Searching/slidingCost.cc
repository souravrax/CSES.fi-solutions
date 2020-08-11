#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

using indexed_set = tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main(){
    fast;
    int n, k;
    cin >> n >> k;
    indexed_set s;
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    for(int i=0; i<k; i++) {
        s.insert(arr[i]);
    }
    int middle = (k-1)/2;
    ll cost = 0;
    int old_mid = *s.find_by_order(middle);
    for(auto i : s) cost+=abs(i - old_mid);
    cout << cost << ' ';
    
    for(int i=k; i<n; i++) {
        auto it = s.upper_bound(arr[i-k]);
        s.erase(it);
        s.insert(arr[i]);
        int mid = *s.find_by_order(middle);
        cost += abs(mid - arr[i]) - abs(old_mid - arr[i-k]);
        if(k%2 == 0) cost -= mid - old_mid;
        old_mid = mid;
        cout << cost << ' ';
    }
    cout << '\n';
}

