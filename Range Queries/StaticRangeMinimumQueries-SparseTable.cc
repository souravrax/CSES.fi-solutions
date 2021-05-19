/**
 *  author: souravrax
 *  created: 18.05.2021 20:55:27
**/
#include <bits/stdc++.h>
using namespace std;

// Range Minimum Query using Sparse Table
const int MAXN = 2e5 + 1;
int log_table[MAXN];
int dp[MAXN][20];
int N, Q, L, R;
void compute_log() { // O(N) preprocessing
    log_table[1] = 0;
    for (int i = 2; i <= N; i++) log_table[i] = log_table[i / 2] + 1;
}

int32_t main() {
    cin >> N >> Q;
    compute_log();
    for (int i = 0; i < N; i++) scanf("%d", &dp[i][0]);
    for (int j = 1; (1 << j) <= N; j++) 
        for (int i = 0; i + (1 << j) <= N; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);

    while (Q--) {
        scanf("%d%d", &L, &R); --L, --R;
        const int& p = log_table[R - L + 1];
        cout << min(dp[L][p], dp[R - (1 << p) + 1][p]) << '\n';
    }
}

