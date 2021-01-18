/**
 *  author: souravrax
 *  created: 17.01.2021 21:10:12
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
using ll = long long;

struct Point {
    int x, y;
    Point operator-(const Point& b) const {
        return Point{x - b.x, y - b.y};
    } // find the vector and return
    void operator -=(const Point& b) {
        x -= b.x;
        y -= b.y;
    } // find the vector and assign

    ll operator*(const Point& b) const {
        return ll(x) * b.y - ll(y) * b.x;
    } // find the cross product of two Points, 

    ll triangle(const Point& a, const Point& b) const {
        return (a - *this) * (b - *this);
    } // for me, check if a is on the left (if returned value is < 0) 
      // or on the right side
      // returned_value == 2 * area of the triangle
};
istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
ostream& operator<<(ostream& os, Point& p) { os << '(' << p.x << ',' << p.y << ")\n"; return os; }

int32_t main() {
    fast; 
    int n;
    cin >> n;
    vector<Point> polygon(n);
    for (Point& point : polygon) cin >> point;
    ll area = 0;
    for (int i = 0; i < n; i++) {
        area += polygon[i] * polygon[(i + 1) % n];
    }
    cout << abs(area) << '\n';
}

