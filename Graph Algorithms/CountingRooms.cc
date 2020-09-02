/**
 *  author: sourav rakshit
 *  created: 02.09.2020 12:29:04
**/

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

int n, m;

void dfs(int i, int j, vector<vector<bool>>& visited, const vector<vector<char>>& mp) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(mp[i][j] == '#' || visited[i][j]) return;

    visited[i][j] = true;

    /* int direction[4][2] = { */
    /*     {0, -1}, */
    /*     {-1, 0}, */
    /*     {1, 0}, */
    /*     {0, 1} */
    /* }; */

    int direction[] = {1, 1, -1, -1};

    for(int x = 0; x < 4; x++) {
        /* if(x&1) { */
        /*     dfs(i , j + direction[x], visited, mp); */
        /* } */
        /* else { */
        /*     dfs(i + direction[x], j, visited, mp); */
        /* } */
        dfs(i + (!(x&1))*direction[x], j + (x&1)*direction[x], visited, mp);
    }
}


int32_t main() {
    fast; 
    int tt = 1;
    while(tt--) {
        cin >> n >> m;
        vector<vector<char>> mp(n, vector<char>(m));
        for(auto& i : mp) for(auto& j : i) cin >> j;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;

        for(int i  = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mp[i][j] != '#' && !visited[i][j]) {
                    cnt++;
                    dfs(i, j, visited, mp);
                }
            }
        }

        cout << cnt << '\n';
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

