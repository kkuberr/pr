#include <iostream>
#include "func.h"
using namespace std;

int main() {

    cout << "Enter point coordinates (x y): ";
    Point p = readPoint();
    cout << "Point: ";
    printPoint(p);
    cout << endl;

    cout << "Enter circle (x y radius): ";
    Circle c = readCircle();
    cout << "Circle: ";
    printCircle(c);
    cout << endl;
    cout << "Length: " << circleLength(c) << endl;
    cout << "Area: " << circleArea(c) << endl;

    cout << "Enter square (x y side): ";
    Square s = readSquare();
    cout << "Square: ";
    printSquare(s);
    cout << endl;
    cout << "Perimeter: " << squarePerimeter(s) << endl;
    cout << "Area: " << squareArea(s) << endl;

    cout << "Point in circle: " << pointInCircle(p, c) << endl;
    cout << "Point in square: " << pointInSquare(p, s) << endl;

    cout << "Point on circle: " << pointOnCircle(p, c) << endl;
    cout << "Point on square: " << pointOnSquare(p, s) << endl;

    return 0;
}