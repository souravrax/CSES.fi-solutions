/**
 *  author: sourav rakshit
 *  created: 12.01.2021 12:38:34
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

void towerOfHanoi(vector<pair<int,int>>& moves, int n, int left, int middle, int right) {
    if (n == 1) {
        moves.emplace_back(left, right);
        return;
    }
    towerOfHanoi(moves, n - 1, left, right, middle);
    moves.emplace_back(left, right);
    towerOfHanoi(moves, n - 1, middle, left, right);
}

int main(int argc, char* argv[]) {
    fast; 
    int n;
    cin >> n;
    vector<pair<int,int>> moves;
    towerOfHanoi(moves, n, 1, 2, 3);
    cout << moves.size() << '\n';
    for (auto& [from, to] : moves) {
        cout << from << ' ' << to << '\n';
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

