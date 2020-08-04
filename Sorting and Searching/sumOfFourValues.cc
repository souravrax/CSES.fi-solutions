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

struct two_sum {
    int start;
    int end;
    ll sum;
    two_sum(int i, int j, ll k) : start(i), end(j), sum(k) {}
    bool shares_points_with(two_sum s) {
        return s.start == start || s.end == start || s.start == end || s.end == end;
    }
    struct less_than {
        bool operator()(const two_sum& a, const two_sum& b) {
            return a.sum < b.sum;
        }
    };
};

int32_t main(){
    fast;
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    
    vector<two_sum> two_sums;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            two_sums.push_back(two_sum(i+1, j+1, (ll)(arr[i] + arr[j])));
        }
    }

    n = two_sums.size();

    sort(all(two_sums), [&](two_sum &a, two_sum &b) {
            return a.sum < b.sum;
            });


    for(int i=0; i<n; i++) {
        if(two_sums[i].sum > x) continue;
        ll c = x - two_sums[i].sum;
        two_sum test(0, 0, c);
        auto it = lower_bound(all(two_sums), test, two_sum::less_than());
        if(it->sum == c && !two_sums[i].shares_points_with(*it)) {
            cout << it->start << ' ' << it->end << ' ' << two_sums[i].start << ' ' << two_sums[i].end << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
