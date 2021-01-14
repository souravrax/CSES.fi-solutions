/**
 *  author: sourav rakshit
 *  created: 12.01.2021 15:43:08
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#define len(x) size(x)
#ifdef LOCAL
#define log(x) cerr << "[ " << #x << " : " << (x) << " ]\n"
#else
#define log(x) (void)0x30
#endif
using ll = long long;
int main(int argc, char* argv[]) {
    fast; 
    int q;
    cin >> q;

#define __int128 uint64_t

    auto resolve = [&](__int128 k) {
        k--;
        __int128 size = 0;
        __int128 mul = 1;
        __int128 dig = 1;
        while (size + mul * 9 * dig < k) {
            size += mul * 9 * dig;
            mul *= 10;
            dig++;
        }
        k -= size;
        __int128 many = k / dig;
        __int128 number = many + mul;
        k %= dig;
        string s = to_string(number);
        return s[k];
    };

    while (q--) {
        __int128 k;
        cin >> k;
        cout << resolve(k) << '\n';
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

