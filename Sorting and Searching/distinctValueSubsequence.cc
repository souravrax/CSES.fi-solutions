#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int64_t binpow(int64_t a, int64_t b)
{
    int64_t res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int64_t inv(int64_t a)
{
    return binpow(a, mod - 2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    int64_t ans = 0;
    map<int, int> mp;
    int64_t total = 1;

    for (int i = 0; i < n; i++)
    {
        total = (total * inv(mp[arr[i]] + 1)) % mod;
        ans = (ans + total) % mod;
        mp[arr[i]]++;
        total = (total * (mp[arr[i]] + 1)) % mod;
    }
    cout << ans;
}
