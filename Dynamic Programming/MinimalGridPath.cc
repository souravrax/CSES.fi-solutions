#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;
int dp[3005][3005];

pair<int, int> dir[] = {{0, -1}, {-1, 0}};

int dfs(int i, int j, int d = 1)
{
    if (i == 0 && j == 0)
    {
        return dp[i][j] = (a[i][j] - 'A' + 1) * d;
    }

    int &ans = dp[i][j];
    if (~ans)
        return ans;
    ans = INT_MAX;

    for (auto &[dx, dy] : dir)
    {
        int nx = i + dx;
        int ny = j + dy;
        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            ans = min(ans, dfs(nx, ny, d + 1) + (a[i][j] - 'A' + 1) * d);
        }
    }

    return ans;
}

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    dfs(n - 1, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int d = 1;
    int i = n - 1, j = n - 1;
    string ans;
    while (i >= 0 && j >= 0)
    {
        ans += a[i][j];
        // cout << i << ' ' << j << endl;
        // cout << dp[i][j] << endl;
        for (auto &[dx, dy] : dir)
        {
            int nx = dx + i;
            int ny = dy + j;
            if (0 <= nx && nx < n && 0 <= ny && ny < n && dp[i][j] == dp[nx][ny] + (a[i][j] - 'A' + 1) * d)
            {
                i = nx;
                j = ny;
                break;
            }
        }
        d++;
        if (i == 0 && j == 0)
        {
            ans += a[i][j];
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
