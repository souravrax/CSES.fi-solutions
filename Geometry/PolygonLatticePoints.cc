/**
 *  author: souravrax
 *  created: 18.01.2021 22:49:03
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
using ll = long long;

struct Point {
    ll x, y;
    Point operator -(const Point& b) const { return Point{x - b.x, y - b.y}; } 
    void operator -=(const Point& b) { x -= b.x, y -= b.y; } 
    ll operator *(const Point& b) const { return ll(x) * b.y - ll(y) * b.x; } 
    ll cross(const Point& a, const Point& b) const { return (a - *this) * (b - *this); } 
    pair<ll, ll> to_pair() const { return make_pair(x, y); }
};
istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
ostream& operator<<(ostream& os, const Point& p) { os << '(' << p.x << ',' << p.y << ")\n"; return os; }

int32_t main() {
    fast; 
    int n;
    cin >> n;
    vector<Point> polygon(n);
    for (Point& p : polygon) cin >> p;
    ll area = 0;
    ll boundary = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        const auto& [a, b] = (polygon[j] - polygon[i]).to_pair();
        boundary += abs(gcd(a, b));
        area += polygon[i] * polygon[j];
    }
    // Pick's theorem
    // area = inside + boundary / 2 - 1
    // 2 * area = 2 * inside + boundary - 2
    // 2 * inside = 2 * area - boundary + 2
    // inside = (2 * area - boundary + 2) / 2;

    ll inside = (abs(area) - boundary + 2) / 2;
    cout << inside << ' ' << boundary << '\n';
}

