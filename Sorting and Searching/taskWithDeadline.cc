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
#define int ll

int32_t main(){
    fast; 
    int n;
    cin >> n;
    vector<pair<int,int>> tasks(n);
    for(auto& i : tasks) {
        cin >> i.first >> i.second;
    }
    sort(all(tasks), [&](pair<int,int> &a, pair<int,int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
            });
    int tim = 0;
    int profit = 0;
    for(auto& [dura, dead] : tasks) {
        tim+=dura;
        profit+=dead - tim;
    }
    cout << profit << '\n';
}

