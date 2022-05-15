// User defined class, Point
#include <iostream>
using namespace std;
class Point
{
    int x; //distancia
    string y; //vertice
public:
    Point(int _x, string _y)
    {
        x = _x;
        y = _y;
    }
    int getX() const { return x; }
    string getY() const { return y; }
};

// To compare two points
class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();
    }
};