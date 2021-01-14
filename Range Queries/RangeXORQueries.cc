/**
 *  author: sourav rakshit
 *  created: 13.01.2021 00:08:36
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr << "[ " << #x << " : " << (x) << " ]\n"
#else
#define log(x) (void)0x30
#endif
using ll = long long;
int main(int argc, char* argv[]) {
    fast; 
    int n, q;
    cin >> n >> q;
    vector<int> xors;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum ^= x;
        xors.push_back(sum);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        int res = xors[b - 1];
        if (a > 1) {
            res ^= xors[a - 2];
        }
        cout << res << "\n";
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}
