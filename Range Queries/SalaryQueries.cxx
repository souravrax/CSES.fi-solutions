#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int bit[MAXN];
int a[MAXN];
int N, Q;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    vector<int> have;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        have.emplace_back(a[i]);
    }
    vector<tuple<char, int, int>> queries(Q);
    for (auto& [t, l, r] : queries) {
        cin >> t >> l >> r;
        if (t == '?') have.emplace_back(l);
        have.emplace_back(r);
    }
    assert((int)size(have) < MAXN);
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());

    memset(bit, 0, sizeof bit);
    auto upd = [&](int idx, int val) { for (idx++; idx <= MAXN; idx += (idx & -idx)) bit[idx] += val; };
    auto qry = [&](int idx) { int res = 0; for (idx++; idx > 0; idx -= (idx & -idx)) res += bit[idx]; return res; };

    for (int i = 0; i < N; i++) {
        a[i] = lower_bound(have.begin(), have.end(), a[i]) - have.begin();
        upd(a[i], 1);
    }
    for (auto& [t, l, r] : queries) {
        if (t == '?') l = lower_bound(have.begin(), have.end(), l) - have.begin();
        r = lower_bound(have.begin(), have.end(), r) - have.begin();

        if (t == '?') {
            cout << qry(r) - qry(l - 1) << '\n';
        } else {
            // l --> k
            // r --> x
            --l;
            upd(a[l], -1);
            a[l] = r;
            upd(a[l], 1);
        }
    }
}

