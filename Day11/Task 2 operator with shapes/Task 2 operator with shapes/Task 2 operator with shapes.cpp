// Geoshape Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Shape {
protected:
    float dim1, dim2;
public:
    Shape() :dim1(0), dim2(0) {
        cout << "default Shape constructor called\n";
    }
    Shape(float dim) :dim1(dim), dim2(dim) {
        cout << "1 param Shape constructor called\n";
    }
    Shape(float x, float y) :dim1(x), dim2(y) {
        cout << "2 param Shape constructor called\n";
    }
    virtual float calcArea() {
        return 0;
    }
    void setDim1(float val) {
        dim1 = val;
    }
    void setDim2(float val) {
        dim2 = val;
    }
    float getDim1() {
        return dim1;
    }
    float getDim2() {
        return dim2;
    }
    ~Shape() {
        cout << "shape des called\n";
    }
};

class Circle :public Shape {
public:
    Circle() :Shape() {
        cout << "default Circle constructor called\n";

    }
    Circle(float r) :Shape(r, r) {
        cout << "Circle constructor called\n";
    }
    Circle & operator=(Circle & c){
    if(this !=&c){
        dim1 = dim2=c.dim1;
    }
    return *this;
    }
    void setRad(float r) {
        dim1 = dim2 = r;
    }
    float calcArea() {
        return 22.0 / 7 * dim1 * dim2;

    }
    ~Circle() {
        cout << "circle des called\n";

    }
};

class Rectangle :public Shape {
public:
    Rectangle() :Shape() {
        cout << "default Rect constructor called\n";

    }
    Rectangle(float x, float y) :Shape(x, y) {
        cout << "Rect constructor called\n";
    }
    Rectangle& operator=(Rectangle& r) {
        if (this != &r) {
            dim1 = r.dim1;
            dim2 = r.dim2;
        }
        return *this;
    }
    float calcArea() {
        return dim1 * dim2;
    }
    ~Rectangle() {
        cout << "Rect des called\n";
    }
};
class Triangle :public Shape {
public:
    Triangle() :Shape() {
        cout << "default Triangle constructor called\n";

    }
    Triangle(float b, float h) :Shape(b, h) {
        cout << "Triangle constructor called\n";
    }
   
    Triangle& operator=(Triangle& t) {
        if (this != &t) {
            dim1 = t.dim1;
            dim2 = t.dim2;
        }
        return *this;
    }
    float calcArea() {
        return 0.5 * dim1 * dim2;
    }
    ~Triangle() {
        cout << "Triangle des called\n";
    }
};

class Square :public Rectangle {
public:
    Square() :Rectangle() {
        cout << "default Square constructor called\n";
    }
    Square(float l) :Rectangle(l, l) {
        cout << "Square constructor called\n";
    }
    Square& operator=(Square& s) {
        if (this != &s) {
            dim1 = s.dim1;
            dim2 = s.dim2;
        }
        return *this;
    }
    void setLen(float l) {
        dim1 = dim2 = l;
    }
    float calcArea() {
        return dim1 * dim2;
    }
    ~Square() {
        cout << "Square des called\n";
    }
};
class Cube :public Square {
public:
    Cube() :Square() {
        cout << "default Cube constructor called\n";
    }
    Cube(float l) :Square(l) {
        cout << "Cube constructor called\n";
    }
    Cube& operator=(Cube& c) {
        if (this != &c) {
            dim1 = c.dim1;
            dim2 = c.dim2;
        }
        return *this;
    }
    float calcArea() {
        return 6 * dim1 * dim2;
    }
    float calcVolume() {
        return dim1 * dim1 * dim1;
    }
    ~Cube() {
        cout << "Cube des called\n";
    }
};
class Rhombus :public Shape {
public:
    Rhombus() :Shape() {
        cout << "default Rhombus constructor called\n";

    }
    Rhombus(float d1, float d2) :Shape(d1, d2) {
        cout << "Rhombus constructor called\n";
    }
    Rhombus& operator=(Rhombus& rh) {
        if (this != &rh) {
            dim1 = rh.dim1;
            dim2 = rh.dim2;
        }
        return *this;
    }
    float calcArea() {
        return (dim1 * dim2) / 2.0;
    }
    ~Rhombus() {
        cout << "Rhombus des called\n";
    }
};

Shape& compare2ShapesArea(Shape&, Shape&);
int main()
{
    Circle c(5);
    cout << "Circle area: " << c.calcArea() << endl;

    Rectangle r(4, 5);
    cout << "Rectangle area: " << r.calcArea() << endl;

    Square sq(3);
    cout << "Square area: " << sq.calcArea() << endl;

    Cube cb(2);
    cout << "Cube area: " << cb.calcArea()
        << ", Volume: " << cb.calcVolume() << endl;

    Rhombus rh(6, 8);
    cout << "Rhombus area: " << rh.calcArea() << endl;
    cout << "The greater area = " << compare2ShapesArea(rh, sq).calcArea() << endl;

    Triangle t1(3, 4);
    Triangle t2;
    t2 = t1;
    cout << "Triangle 1 area: " << t1.calcArea() << endl;
    cout << "Triangle 2 area: " << t2.calcArea() << endl;

}

Shape& compare2ShapesArea(Shape& obj1, Shape& obj2) {
    if (obj1.calcArea() > obj2.calcArea())
        return obj1;
    else
        return obj2;
}