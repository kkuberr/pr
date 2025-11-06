#ifndef FUNC_H
#define FUNC_H

#include "structs.h"

Point readPoint();
void printPoint(Point p);

Circle readCircle();
void printCircle(Circle c);
double circleLength(Circle c);
double circleArea(Circle c);

Square readSquare();
void printSquare(Square s);
double squarePerimeter(Square s);
double squareArea(Square s);

bool pointInCircle(Point p, Circle c);
bool pointInSquare(Point p, Square s);

bool pointOnCircle(Point p, Circle c);
bool pointOnSquare(Point p, Square s);

bool circlesIntersect(Circle c1, Circle c2);
bool squaresIntersect(Square s1, Square s2);
bool circleSquareIntersect(Circle c, Square s);

bool circleInCircle(Circle c1, Circle c2);
bool squareInSquare(Square s1, Square s2);
bool squareInCircle(Square s, Circle c);
bool circleInSquare(Circle c, Square s);

#endif