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
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    stack<pair<int,int>> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && st.top().first >= arr[i]) st.pop();
        if(st.empty()) cout << 0 << ' ';
        else cout << st.top().second << ' ';
        st.push({arr[i], i+1});
    }
    cout << '\n';
}

