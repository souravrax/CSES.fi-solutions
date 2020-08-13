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

set<int> ans;

int32_t main(){
    fast; 
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr) cin >> i;

    set<int> s;
    for(int i=0; i<n; i++) {
        int curr = arr[i];
        set<int> exist = s;
        for(auto e : exist) {
            s.insert(curr + e);
        }
        s.insert(curr);
    }

    cout << s.size() << '\n';
    for(auto i : s) {
        cout << i << ' ';
    }
    cout << '\n';
}

