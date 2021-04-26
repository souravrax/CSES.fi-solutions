/**
 *  author: souravrax
 *  created: 26.04.2021 13:57:29
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "[ " << #__VA_ARGS__ << " ]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...) (void)0x30
#endif
using ll = long long;

pair<int, int> moves[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    pair<int, int> hero;
    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    vector<vector<int>> takes(n, vector<int>(m, 2e9));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'M') {
                matrix[i][j] = true;
                takes[i][j] = 0;
                q.push({i, j});
            } else if (c == '.') {
                matrix[i][j] = true;
            } else if (c == 'A') {
                matrix[i][j] = true;
                hero = {i, j};
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (matrix[nx][ny] && takes[nx][ny] > takes[x][y] + 1) {
                    takes[nx][ny] = takes[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
/* for (int i = 0; i < n; i++) { */
/* for (int j = 0; j < m; j++) { */
/* if (!matrix[i][j]) { */
/* cout << "$ "; */
/* } else { */
/* cout << takes[i][j] << ' '; */
/* } */
/* } */
/* cout << '\n'; */
/* } */
    q.push(hero);
    vector<vector<int>> can(n, vector<int>(m, 2e9));
    can[hero.first][hero.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (matrix[nx][ny] && takes[nx][ny] > can[x][y] + 1) {
                    if (can[nx][ny] > can[x][y] + 1) {
                        can[nx][ny] = can[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    pair<int, int> cell;
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (can[i][j] < 2e9) {
                    cell = {i, j};
                    found = true;
                }
            }
        }
    }
    if (!found) {
        cout << "NO\n";
        return 0;
    }
    string d = "LURD";
    string ans;
    while (cell != hero) {
        auto [x, y] = cell;
        for (int i = 0; i < 4; i++) {
            int nx = x + moves[i].first;
            int ny = y + moves[i].second;
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (can[nx][ny] == can[x][y] - 1) {
                    ans += d[i];
                    cell = {nx, ny};
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    cout << len(ans) << '\n';
    reverse(all(ans));
    cout << ans << '\n';
}

