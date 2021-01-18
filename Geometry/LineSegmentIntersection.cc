#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Remember: complex is slow
struct Point {
    int x, y;
    Point operator -(const Point& b) const { return Point{x - b.x, y - b.y}; } 
    void operator -=(const Point& b) { x -= b.x, y -= b.y; } 
    ll operator *(const Point& b) const { return ll(x) * b.y - ll(y) * b.x; } 
    ll cross(const Point& a, const Point& b) const { return (a - *this) * (b - *this); } 
};
istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
ostream& operator<<(ostream& os, Point& p) { os << '(' << p.x << ',' << p.y << ")\n"; return os; }

bool isIntersecting(Point& p1, Point& p2, Point& p3, Point& p4) {
    if ((p2 - p1) * (p4 - p3) == 0LL) {
        if (p1.cross(p2, p3) != 0LL) {
            return false;
        } else {
            for (int rep = 0; rep < 2; rep++) {
                if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                    return false;
                }
                swap(p1, p3);
                swap(p2, p4);
            }
        }
        return true;
    }
    else {
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
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        Point p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;
        if (isIntersecting(p1, p2, p3, p4)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
