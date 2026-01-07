#include "SimpleGraphics.h"
#include <iostream>
#include <vector>
using namespace std;

class Point {
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int h) : x(h), y(h) {}
    Point(int h, int l) : x(h), y(l) {}
    int getX() { return x; }
    int getY() { return y; }
    ~Point() { cout << "Point dest called\n"; }
};

class Line {
    Point start, end;
public:
    Line() : start(Point()), end(Point()) {}
    Line(int x1, int y1, int x2, int y2) : start(Point(x1, y1)), end(Point(x2, y2)) {}
    Line(Line& l) : start(l.start), end(l.end) {}
    Line& operator=(Line& l) {
        if (this != &l) {
            start = l.start;
            end = l.end;
        }
        return *this;
    }
    void draw(char c = '#') {
        drawLine(start.getX(), start.getY(), end.getX(), end.getY(), c);
    }
    ~Line() { cout << "Line dest called\n"; }
};

class Circle {
    Point center;
    int r;
public:
    Circle() : r(0), center(Point()) {}
    Circle(int x, int y, int radius) : r(radius), center(Point(x, y)) {}
    Circle(Circle& c) : center(c.center), r(c.r) {}
    Circle& operator=(Circle& c) {
        if (this != &c) {
            center = c.center;
            r = c.r;
        }
        return *this;
    }
    void draw(char c = '#') {
        drawCircle(center.getX(), center.getY(), r, c);
    }
    ~Circle() {}
};

class Rect {
    Point ul, lr;
public:
    Rect() : ul(Point()), lr(Point()) {}
    Rect(int x1, int y1, int x2, int y2) : ul(Point(x1, y1)), lr(Point(x2, y2)) {}
    Rect(Rect& r) : ul(r.ul), lr(r.lr) {}
    Rect& operator=(Rect& r) {
        if (this != &r) {
            ul = r.ul;
            lr = r.lr;
        }
        return *this;
    }
    void draw(char c = '#') {
        drawRect(ul.getX(), ul.getY(), lr.getX(), lr.getY(), c);
    }
    ~Rect() { cout << "Rect dest called\n"; }
};

class Triangle {
    Point a, b, c;
public:
    Triangle() : a(Point()), b(Point()), c(Point()) {}
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
        : a(Point(x1, y1)), b(Point(x2, y2)), c(Point(x3, y3)) {
    }
    Triangle(Triangle& t) : a(t.a), b(t.b), c(t.c) {}
    Triangle& operator=(Triangle& t) {
        if (this != &t) {
            a = t.a;
            b = t.b;
            c = t.c;
        }
        return *this;
    }
    void draw(char ch = '#') {
        drawTriangle(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY(), ch);
    }
    ~Triangle() { cout << "Triangle destructor called\n"; }
};

class Ellipse {
    Point f1, f2;
    int r;
public:
    Ellipse() : r(0), f1(Point()), f2(Point()) {}
    Ellipse(int radius, int x1, int y1, int x2, int y2) : r(radius), f1(Point(x1, y1)), f2(Point(x2, y2)) {}
    Ellipse(Ellipse& e) : f1(e.f1), f2(e.f2), r(e.r) {}
    Ellipse& operator=(Ellipse& e) {
        if (this != &e) {
            f1 = e.f1;
            f2 = e.f2;
            r = e.r;
        }
        return *this;
    }
    void draw(char c = '#') {
        drawEllipse(f1.getX(), f1.getY(), f2.getX(), f2.getY(), r, c);
    }
    ~Ellipse() { cout << "Ellipse destructor called\n"; }
};

class Picture {
    vector<Circle> circles;
    vector<Rect> rects;
    vector<Line> lines;
    vector<Triangle> triangles;
    vector<Ellipse> ellipses;
public:
    Picture() : circles(), rects(), lines(), triangles(), ellipses() {}

    Picture(int nc, int nr, int nl, int nt, int ne)
        : circles(nc), rects(nr), lines(nl), triangles(nt), ellipses(ne) {
    }

    Picture(Picture& p)
        : circles(p.circles), rects(p.rects), lines(p.lines),
        triangles(p.triangles), ellipses(p.ellipses) {
    }

    Picture& operator=(Picture& p) {
        if (this != &p) {
            circles = p.circles;
            rects = p.rects;
            lines = p.lines;
            triangles = p.triangles;
            ellipses = p.ellipses;
        }
        return *this;
    }

    void setCircle(int i, int x, int y, int r) { circles[i] = Circle(x, y, r); }
    void setRect(int i, int x1, int y1, int x2, int y2) { rects[i] = Rect(x1, y1, x2, y2); }
    void setLine(int i, int x1, int y1, int x2, int y2) { lines[i] = Line(x1, y1, x2, y2); }
    void setTriangle(int i, int x1, int y1, int x2, int y2, int x3, int y3) { triangles[i] = Triangle(x1, y1, x2, y2, x3, y3); }
    void setEllipse(int i, int r, int x1, int y1, int x2, int y2) { ellipses[i] = Ellipse(r, x1, y1, x2, y2); }

    void draw() {
        for (size_t i = 0; i < circles.size(); i++) circles[i].draw();
        for (size_t i = 0; i < rects.size(); i++) rects[i].draw();
        for (size_t i = 0; i < lines.size(); i++) lines[i].draw();
        for (size_t i = 0; i < triangles.size(); i++) triangles[i].draw();
        for (size_t i = 0; i < ellipses.size(); i++) ellipses[i].draw();
    }

    ~Picture() {}
};

int main() {
    initScreen();

    Picture pic(2, 1, 2, 1, 1);

    pic.setCircle(0, 40, 15, 8);
    pic.setCircle(1, 60, 15, 5);

    pic.setRect(0, 5, 5, 20, 10);

    pic.setLine(0, 10, 10, 50, 30);
    pic.setLine(1, 20, 5, 30, 25);

    pic.setTriangle(0, 60, 20, 70, 20, 65, 10);

    pic.setEllipse(0, 10, 30, 25, 35, 25);

    pic.draw();

    renderScreen();

    return 0;
}
