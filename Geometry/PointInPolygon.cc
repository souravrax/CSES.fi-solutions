/**
 *  author: souravrax
 *  created: 18.01.2021 12:56:10
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#define log(...) cerr << #__VA_ARGS__ << ' ' << ": " << __VA_ARGS__ << endl
using ll = long long;

struct Point {
    ll x, y;
    Point operator -(const Point& b) const { return Point{x - b.x, y - b.y}; } 
    void operator -=(const Point& b) { x -= b.x, y -= b.y; } 
    ll operator *(const Point& b) const { return ll(x) * b.y - ll(y) * b.x; } 
    ll cross(const Point& a, const Point& b) const { return (a - *this) * (b - *this); } 
};
istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
ostream& operator<<(ostream& os, const Point& p) { os << '(' << p.x << ',' << p.y << ")\n"; return os; }

bool intersects(Point p1, Point p2, Point p3, Point p4) {
    if ((p2 - p1) * (p4 - p3) == 0LL) { // if they are parallel
        if (p1.cross(p2, p3) != 0LL) {
            return false;
        }
        for (int rep = 0; rep < 2; rep++) {
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
    for (int rep = 0; rep < 2; rep++) {
        ll sign1 = p1.cross(p2, p3);
        ll sign2 = p1.cross(p2, p4);
        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            return false;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return true;
}

bool is_inside(const Point& a, const Point& b, const Point& c) {
    if (a.cross(b, c) != 0) return false;
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

const ll INF = 3e9;

int32_t main() {
    fast; 
    int n, q;
    cin >> n >> q;
    vector<Point> polygon(n);
    for (auto& i : polygon) cin >> i;

    while (q--) {
        Point p;
        cin >> p;
        int cnt = 0;
        bool on_boundary = false;
        Point out{p.x + 1, INF};
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (is_inside(polygon[i], polygon[j], p)) {
                on_boundary = true;
                break;
            }
            cnt += intersects(p, out, polygon[i], polygon[j]);
        }
        if (on_boundary) {
            cout << "BOUNDARY\n";
        } else if (cnt&1) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
}

