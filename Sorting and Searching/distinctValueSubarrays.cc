#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    long long ans = 0;
    map<int, int> mp;
    for (int l = 0, r = 0; r < n; r++)
    {
        mp[arr[r]]++;
        while (l < r && mp[arr[r]] > 1)
        {
            mp[arr[l++]]--;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}