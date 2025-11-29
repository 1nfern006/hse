#include <iostream>
#include <vector>
#include <algorithm>


struct Point {
    int x;
    int y;
    long long distsq = x * x + y * y;
};


bool sortPoints(const Point& a, const Point& b) {
    return a.distsq < b.distsq;
}

int main() {

    int n;
    std::cin >> n;

    std::vector<Point> points(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        points[i].distsq = points[i].x * points[i].x + points[i].y * points[i].y;
    }

    sort(points.begin(), points.end(), sortPoints);


    for (int i = 0; i < n; ++i) {
        std::cout << points[i].x << " " << points[i].y << '\n';
    }

    return 0;
}