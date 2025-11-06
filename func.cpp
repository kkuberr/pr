#include "func.h"
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const double EPS = 1e-5;

bool equal(double a, double b) {
    return fabs(a - b) < EPS;
}

bool lessOrEqual(double a, double b) {
    return a < b || equal(a, b);
}

bool greaterOrEqual(double a, double b) {
    return a > b || equal(a, b);
}

Point readPoint() {
    Point p;
    cin >> p.x >> p.y;
    return p;
}

void printPoint(Point p) {
    cout << "(" << p.x << ", " << p.y << ")";
}

Circle readCircle() {
    Circle c;
    cin >> c.center.x >> c.center.y >> c.radius;
    return c;
}

void printCircle(Circle c) {
    cout << "Center: (" << c.center.x << ", " << c.center.y << "), Radius: " << c.radius;
}

double circleLength(Circle c) {
    return 2 * 3.141592653 * c.radius;
}

double circleArea(Circle c) {
    return 3.141592653 * c.radius * c.radius;
}

Square readSquare() {
    Square s;
    cin >> s.topLeft.x >> s.topLeft.y >> s.side;
    return s;
}

void printSquare(Square s) {
    cout << "Top-Left: (" << s.topLeft.x << ", " << s.topLeft.y << "), Side: " << s.side;
}

double squarePerimeter(Square s) {
    return 4 * s.side;
}

double squareArea(Square s) {
    return s.side * s.side;
}

bool pointInCircle(Point p, Circle c) {
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    return dx*dx + dy*dy < c.radius*c.radius - EPS;
}

bool pointInSquare(Point p, Square s) {
    return (p.x > s.topLeft.x + EPS) &&
           (p.x < s.topLeft.x + s.side - EPS) &&
           (p.y < s.topLeft.y - EPS) &&
           (p.y > s.topLeft.y - s.side + EPS);
}

bool pointOnCircle(Point p, Circle c) {
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    return equal(dx*dx + dy*dy, c.radius*c.radius);
}

bool pointOnSquare(Point p, Square s) {
    bool onVertical = (equal(p.x, s.topLeft.x) || equal(p.x, s.topLeft.x + s.side)) &&
                      lessOrEqual(p.y, s.topLeft.y) && greaterOrEqual(p.y, s.topLeft.y - s.side);
    bool onHorizontal = (equal(p.y, s.topLeft.y) || equal(p.y, s.topLeft.y - s.side)) &&
                      lessOrEqual(p.x, s.topLeft.x + s.side) && greaterOrEqual(p.x, s.topLeft.x);
    return onVertical || onHorizontal;
}

bool circlesIntersect(Circle c1, Circle c2) {
    double dx = c1.center.x - c2.center.x;
    double dy = c1.center.y - c2.center.y;
    double distance = sqrt(dx*dx + dy*dy);
    return lessOrEqual(distance, c1.radius + c2.radius) &&
           greaterOrEqual(distance, fabs(c1.radius - c2.radius));
}

bool squaresIntersect(Square s1, Square s2) {
    bool xOverlap = s1.topLeft.x < s2.topLeft.x + s2.side + EPS &&
                    s1.topLeft.x + s1.side > s2.topLeft.x - EPS;
    bool yOverlap = s1.topLeft.y > s2.topLeft.y - s2.side - EPS &&
                    s1.topLeft.y - s1.side < s2.topLeft.y + EPS;
    return xOverlap && yOverlap;
}

bool circleSquareIntersect(Circle c, Square s) {
    Point corners[4] = {
        {s.topLeft.x, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y - s.side},
        {s.topLeft.x, s.topLeft.y - s.side}
    };

    for (int i = 0; i < 4; i++) {
        if (pointInCircle(corners[i], c) || pointOnCircle(corners[i], c)) return true;
    }

    double closestX = clamp(c.center.x, s.topLeft.x, s.topLeft.x + s.side);
    double closestY = clamp(c.center.y, s.topLeft.y - s.side, s.topLeft.y);
    double dx = c.center.x - closestX;
    double dy = c.center.y - closestY;
    return (dx*dx + dy*dy) <= c.radius*c.radius + EPS;
}

bool circleInCircle(Circle c1, Circle c2) {
    double dx = c1.center.x - c2.center.x;
    double dy = c1.center.y - c2.center.y;
    double distance = sqrt(dx*dx + dy*dy);
    return lessOrEqual(distance + c1.radius, c2.radius);
}

bool squareInSquare(Square s1, Square s2) {
    return greaterOrEqual(s1.topLeft.x, s2.topLeft.x - EPS) &&
           lessOrEqual(s1.topLeft.x + s1.side, s2.topLeft.x + s2.side + EPS) &&
           lessOrEqual(s1.topLeft.y, s2.topLeft.y + EPS) &&
           greaterOrEqual(s1.topLeft.y - s1.side, s2.topLeft.y - s2.side - EPS);
}

bool squareInCircle(Square s, Circle c) {
    Point corners[4] = {
        {s.topLeft.x, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y - s.side},
        {s.topLeft.x, s.topLeft.y - s.side}
    };

    for (int i = 0; i < 4; i++) {
        double dx = corners[i].x - c.center.x;
        double dy = corners[i].y - c.center.y;
        if (dx*dx + dy*dy > c.radius*c.radius + EPS) return false;
    }
    return true;
}

bool circleInSquare(Circle c, Square s) {
    return (c.center.x - c.radius > s.topLeft.x - EPS) &&
           (c.center.x + c.radius < s.topLeft.x + s.side + EPS) &&
           (c.center.y + c.radius < s.topLeft.y + EPS) &&
           (c.center.y - c.radius > s.topLeft.y - s.side - EPS);
}