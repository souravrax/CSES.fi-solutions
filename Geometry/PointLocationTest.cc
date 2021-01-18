/**
 *  author: sourav rakshit
 *  created: 17.01.2021 12:23:36
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

struct Point {
    int x, y;
    Point operator-(const Point& b) const {
        return Point{x - b.x, y - b.y};
    }
    void operator -=(const Point& b) {
        x -= b.x;
        y -= b.y;
    }

    ll operator*(const Point& b) const {
        return ll(x) * b.y - ll(y) * b.x;
    }
};

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

void solve() {
    Point a, b, c;
    cin >> a >> b >> c;
    b -= a;
    c -= a;
    ll res = b * c;
    if (res < 0) {
        cout << "RIGHT\n";
    }
    else if (res > 0) {
        cout << "LEFT\n";
    }
    else {
        cout << "TOUCH\n";
    }
}

int main(int argc, char* argv[]) {
    fast; 
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}

