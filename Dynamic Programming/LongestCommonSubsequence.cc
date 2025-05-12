#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int solve(int i, int j, vector<int> &a, vector<int> &b)
{
    int &ans = dp[i][j];
    if (~ans)
        return ans;
    ans = 0;
    if (i == 0 || j == 0)
        return ans = 0;

    if (a[i - 1] == b[j - 1])
    {
        return ans = 1 + solve(i - 1, j - 1, a, b);
    }
    return ans = max({ans,
                      solve(i - 1, j, a, b),
                      solve(i, j - 1, a, b)});
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    memset(dp, -1, sizeof dp);
    cout << solve(n, m, a, b) << endl;
    int i = n, j = m;
    vector<int> ans;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans.push_back(a[i - 1]);
            i--, j--;
        }
        else if (dp[i - 1][j] == dp[i][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for (int i = ans.size() - 1; ~i; i--)
    {
        cout << ans[i] << ' ';
    }
}
