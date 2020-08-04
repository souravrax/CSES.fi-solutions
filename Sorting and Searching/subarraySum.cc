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
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    queue<int> q;
    int cnt = 0;
    ll sum = 0;
    for(const int& i : arr) {
        sum+=i;
        q.push(i);
        while(!q.empty() && sum > x) {
            sum-=q.front();
            q.pop();
        }
        if(sum == x) cnt++;
    }
    cout << cnt << '\n';
}

