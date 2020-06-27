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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef multimap<pii, int> miii;
typedef priority_queue<pii, vector<pii>, greater<pii>> pq;

int32_t main() {
    fast;
    int n, k = 0;
    cin >> n;
    miii m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m.insert({{a, b}, i});
    }
    pq q;
    vi v(n);
    for(auto [x,index] : m) {
        int c;
        auto [a,b] = x;
        if (q.empty() || q.top().first >= a) {
            c = ++k;
        } else {
            c = q.top().second;
            q.pop();
        }
        q.push({b, c});
        v[index] = c;
    }
    cout << k << '\n';
    for(auto i : v) cout << i << ' ';
    cout << '\n';
}
