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
    string s;
    cin>>s;
    sort(all(s));
    vector<string> res;
    do {
        res.push_back(s);
    } while(next_permutation(all(s)));
    cout << res.size() << '\n';
    for(auto i : res) {
        cout << i << '\n';
    }
}

