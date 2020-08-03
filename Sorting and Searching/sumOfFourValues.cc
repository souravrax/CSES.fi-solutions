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
    vector<tuple<int,int>> arr(n);
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        arr[i] = {t, i+1};
    }
    sort(all(arr));

    for(int i=0; i<=n-4; i++) {
        for(int j=i+1; j<=n-3; j++) {
            for(int k=j+1; k<=n-2; k++) {
                for(int l=k+1; l<=n-1; l++) {
                    if(x == get<0>(arr[i]) + get<0>(arr[j]) + get<0>(arr[k]) + get<0>(arr[l])) {
                        cout << get<1>(arr[i]) << ' ' << get<1>(arr[j]) << ' ' << get<1>(arr[k]) << ' ' << get<1>(arr[l]) << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}


