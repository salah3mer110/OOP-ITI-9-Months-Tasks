// Geoshape Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
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
    virtual float calcArea() = 0;
    virtual float calcVolume() {
        return 0;
    };
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

    float calcArea() {
        return (dim1 * dim2) / 2.0;
    }
    ~Rhombus() {
        cout << "Rhombus des called\n";
    }
};
bool compare2ShapesArea(Shape*, Shape*);

int main()
{
    Shape* s;
    s = new Circle(3);
    cout << "Volume = " << s->calcVolume() << endl;
    cout<<"Area = "<<s->calcArea()<<endl;
    s = new Square(4);
    cout << "Volume = " << s->calcVolume() << endl;
    cout << "Area = " << s->calcArea() << endl;
    s = new Rectangle(3,4);
    cout << "Volume = " << s->calcVolume() << endl;
    cout << "Area = " << s->calcArea() << endl;
    s = new Cube(5);
    cout << "Area = " << s->calcArea() << endl;
    cout << "Volume = " << s->calcVolume() << endl;
    s = new Rhombus(3,2);
    cout << "Volume = " << s->calcVolume() << endl;
    cout << "Area = " << s->calcArea() << endl;
    delete s;
    s = nullptr;


    vector<Shape*>shapes;
    shapes.push_back(new Circle(3));
    shapes.push_back(new Square(4));
    shapes.push_back(new Rectangle(3,4));
    shapes.push_back(new Cube(5));
    shapes.push_back(new Rhombus(3,2));
    sort(shapes.begin(), shapes.end(), compare2ShapesArea);
    cout << "\n\sort\n";
    for (auto shape : shapes) {
        cout << "Area = " << shape->calcArea()
            << ", Volume = " << shape->calcVolume() << endl;
        delete shape;
    }
}
bool compare2ShapesArea(Shape* obj1, Shape* obj2) {
    return obj1->calcArea() > obj2->calcArea();
}