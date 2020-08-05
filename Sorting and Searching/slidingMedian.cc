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

int32_t main(){
    fast; 
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;
    int median = (k-1)/2;
    for(int i=0; i<n; i++) {
        s.insert(arr[i]);
        if(i >= k-1) {
            cout << *s.find_by_order(median) << ' ';
            auto it = s.upper_bound(arr[i - k + 1]);
            s.erase(it);
        }
    }
    cout << '\n';
}

