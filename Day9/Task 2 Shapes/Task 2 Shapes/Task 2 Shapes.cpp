#include "SimpleGraphics.h"
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point() :x(0), y(0) {}
	Point(int h) :x(h), y(h) {}
	Point(int h, int l) :x(h), y(l) {}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	~Point() {
		cout << "Point dest called\n";
	}
};

class Line {
	Point* start;
	Point* end;
public:
	Line() :start(new Point()), end(new Point()) {}
	Line(int x1, int y1, int x2, int y2) :start(new Point(x1, y1)), end(new Point(x2, y2)) {}

	Line(Line& l) {
		start = new Point(*l.start);
		end = new Point(*l.end);
	}

	Line& operator=(Line& l) {
		if (this != &l) {
			delete start;
			delete end;
			start = new Point(*l.start);
			end = new Point(*l.end);
		}
		return *this;
	}

	void draw(char c = '#') {
		drawLine(start->getX(), start->getY(), end->getX(), end->getY(), c);
	}

	~Line() {
		delete start;
		delete end;
		start = end = nullptr;
		cout << "Line dest called\n";
	}
};

class Circle {
	Point* center;
	int r;
public:
	Circle() :r(0), center(new Point()) {}
	Circle(int x, int y, int radius) :r(radius), center(new Point(x, y)) {}

	Circle(Circle& c) {
		center = new Point(*c.center);
		r = c.r;
	}

	Circle& operator=(Circle& c) {
		if (this != &c) {
			delete center;
			center = new Point(*c.center);
			r = c.r;
		}
		return *this;
	}

	void draw(char c = '#') {
		drawCircle(center->getX(), center->getY(), r, c);
	}

	~Circle() {
		delete center;
		center = nullptr;
	}
};

class Rect {
	Point* ul;
	Point* lr;
public:
	Rect() :ul(new Point()), lr(new Point()) {}
	Rect(int x1, int y1, int x2, int y2) :ul(new Point(x1, y1)), lr(new Point(x2, y2)) {}

	Rect(Rect& r) {
		ul = new Point(*r.ul);
		lr = new Point(*r.lr);
	}

	Rect& operator=(Rect& r) {
		if (this != &r) {
			delete ul;
			delete lr;
			ul = new Point(*r.ul);
			lr = new Point(*r.lr);
		}
		return *this;
	}

	void draw(char c = '#') {
		drawRect(ul->getX(), ul->getY(), lr->getX(), lr->getY(), c);
	}

	~Rect() {
		delete ul;
		delete lr;
		ul = lr = nullptr;
		cout << "Rect dest called\n";
	}
};

class Triangle {
	Point* a;
	Point* b;
	Point* c;
public:
	Triangle() :a(new Point()), b(new Point()), c(new Point()) {}
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) :a(new Point(x1, y1)), b(new Point(x2, y2)), c(new Point(x3, y3)) {}

	Triangle(Triangle& t) {
		a = new Point(*t.a);
		b = new Point(*t.b);
		c = new Point(*t.c);
	}

	Triangle& operator=(Triangle& t) {
		if (this != &t) {
			delete a;
			delete b;
			delete c;
			a = new Point(*t.a);
			b = new Point(*t.b);
			c = new Point(*t.c);
		}
		return *this;
	}

	void draw(char ch = '#') {
		drawTriangle(a->getX(), a->getY(), b->getX(), b->getY(), c->getX(), c->getY(), ch);
	}

	~Triangle() {
		delete a;
		delete b;
		delete c;
		a = b = c = nullptr;
		cout << "Triangle destructor called\n";
	}
};

class Ellipse {
	Point* f1;
	Point* f2;
	int r;
public:
	Ellipse() :r(0), f1(new Point()), f2(new Point()) {}
	Ellipse(int radius, int x1, int y1, int x2, int y2) :r(radius), f1(new Point(x1, y1)), f2(new Point(x2, y2)) {}

	Ellipse(Ellipse& e) {
		f1 = new Point(*e.f1);
		f2 = new Point(*e.f2);
		r = e.r;
	}

	Ellipse& operator=(Ellipse& e) {
		if (this != &e) {
			delete f1;
			delete f2;
			f1 = new Point(*e.f1);
			f2 = new Point(*e.f2);
			r = e.r;
		}
		return *this;
	}

	void draw(char c = '#') {
		drawEllipse(f1->getX(), f1->getY(), f2->getX(), f2->getY(), r, c);
	}

	~Ellipse() {
		delete f1;
		delete f2;
		f1 = f2 = nullptr;
		cout << "Ellipse destructor called\n";
	}
};

class Picture {
	Circle** circles;
	Rect** rects;
	Line** lines;
	Triangle** triangles;
	Ellipse** ellipses;
	int numCircles;
	int numRects;
	int numLines;
	int numTriangles;
	int numEllipses;
public:
	Picture() : circles(nullptr), rects(nullptr), lines(nullptr),
		triangles(nullptr), ellipses(nullptr),
		numCircles(0), numRects(0), numLines(0),
		numTriangles(0), numEllipses(0) {
	}

	Picture(int nc, int nr, int nl, int nt, int ne)
		: numCircles(nc), numRects(nr), numLines(nl),
		numTriangles(nt), numEllipses(ne) {

		circles = nc > 0 ? new Circle * [nc] : nullptr;
		lines = nl > 0 ? new Line * [nl] : nullptr;
		rects = nr > 0 ? new Rect * [nr] : nullptr;
		triangles = nt > 0 ? new Triangle * [nt] : nullptr;
		ellipses = ne > 0 ? new Ellipse * [ne] : nullptr;

		for (int i = 0; i < nc; i++) circles[i] = nullptr;
		for (int i = 0; i < nr; i++) rects[i] = nullptr;
		for (int i = 0; i < nl; i++) lines[i] = nullptr;
		for (int i = 0; i < nt; i++) triangles[i] = nullptr;
		for (int i = 0; i < ne; i++) ellipses[i] = nullptr;
	}

	Picture(Picture& p)
		: numCircles(p.numCircles), numRects(p.numRects),
		numLines(p.numLines), numTriangles(p.numTriangles),
		numEllipses(p.numEllipses) {

		circles = (numCircles > 0) ? new Circle * [numCircles] : nullptr;
		rects = (numRects > 0) ? new Rect * [numRects] : nullptr;
		lines = (numLines > 0) ? new Line * [numLines] : nullptr;
		triangles = (numTriangles > 0) ? new Triangle * [numTriangles] : nullptr;
		ellipses = (numEllipses > 0) ? new Ellipse * [numEllipses] : nullptr;

		for (int i = 0; i < numCircles; i++) {
			circles[i] = p.circles[i] ? new Circle(*p.circles[i]) : nullptr;
		}
		for (int i = 0; i < numRects; i++) {
			rects[i] = p.rects[i] ? new Rect(*p.rects[i]) : nullptr;
		}
		for (int i = 0; i < numLines; i++) {
			lines[i] = p.lines[i] ? new Line(*p.lines[i]) : nullptr;
		}
		for (int i = 0; i < numTriangles; i++) {
			triangles[i] = p.triangles[i] ? new Triangle(*p.triangles[i]) : nullptr;
		}
		for (int i = 0; i < numEllipses; i++) {
			ellipses[i] = p.ellipses[i] ? new Ellipse(*p.ellipses[i]) : nullptr;
		}
	}

	Picture& operator=(Picture& p) {
		if (this != &p) {
			for (int i = 0; i < numCircles; i++) {
				delete circles[i];
			}
			for (int i = 0; i < numRects; i++) {
				delete rects[i];
			}
			for (int i = 0; i < numLines; i++) {
				delete lines[i];
			}
			for (int i = 0; i < numTriangles; i++) {
				delete triangles[i];
			}
			for (int i = 0; i < numEllipses; i++) {
				delete ellipses[i];
			}
			delete[]circles;
			delete[]lines;
			delete[]triangles;
			delete[]rects;
			delete[]ellipses;

			numCircles = p.numCircles;
			numRects = p.numRects;
			numLines = p.numLines;
			numTriangles = p.numTriangles;
			numEllipses = p.numEllipses;

			circles = (numCircles > 0) ? new Circle * [numCircles] : nullptr;
			rects = (numRects > 0) ? new Rect * [numRects] : nullptr;
			lines = (numLines > 0) ? new Line * [numLines] : nullptr;
			triangles = (numTriangles > 0) ? new Triangle * [numTriangles] : nullptr;
			ellipses = (numEllipses > 0) ? new Ellipse * [numEllipses] : nullptr;

			for (int i = 0; i < numCircles; i++) {
				circles[i] = p.circles[i] ? new Circle(*p.circles[i]) : nullptr;
			}
			for (int i = 0; i < numRects; i++) {
				rects[i] = p.rects[i] ? new Rect(*p.rects[i]) : nullptr;
			}
			for (int i = 0; i < numLines; i++) {
				lines[i] = p.lines[i] ? new Line(*p.lines[i]) : nullptr;
			}
			for (int i = 0; i < numTriangles; i++) {
				triangles[i] = p.triangles[i] ? new Triangle(*p.triangles[i]) : nullptr;
			}
			for (int i = 0; i < numEllipses; i++) {
				ellipses[i] = p.ellipses[i] ? new Ellipse(*p.ellipses[i]) : nullptr;
			}
		}
		return *this;
	}

	void setCircle(int index, Circle* c) {
		if (index >= 0 && index < numCircles) {
			delete circles[index];
			circles[index] = c;
		}
	}

	void setRect(int index, Rect* r) {
		if (index >= 0 && index < numRects) {
			delete rects[index];
			rects[index] = r;
		}
	}

	void setLine(int index, Line* l) {
		if (index >= 0 && index < numLines) {
			delete lines[index];
			lines[index] = l;
		}
	}

	void setTriangle(int index, Triangle* t) {
		if (index >= 0 && index < numTriangles) {
			delete triangles[index];
			triangles[index] = t;
		}
	}

	void setEllipse(int index, Ellipse* e) {
		if (index >= 0 && index < numEllipses) {
			delete ellipses[index];
			ellipses[index] = e;
		}
	}

	void draw() {
		for (int i = 0; i < numCircles; i++) {
			if (circles[i]) circles[i]->draw();
		}
		for (int i = 0; i < numRects; i++) {
			if (rects[i]) rects[i]->draw();
		}
		for (int i = 0; i < numLines; i++) {
			if (lines[i]) lines[i]->draw();
		}
		for (int i = 0; i < numTriangles; i++) {
			if (triangles[i]) triangles[i]->draw();
		}
		for (int i = 0; i < numEllipses; i++) {
			if (ellipses[i]) ellipses[i]->draw();
		}
	}

	~Picture() {
		for (int i = 0; i < numCircles; i++) {
			delete circles[i];
		}
		for (int i = 0; i < numRects; i++) {
			delete rects[i];
		}
		for (int i = 0; i < numLines; i++) {
			delete lines[i];
		}
		for (int i = 0; i < numTriangles; i++) {
			delete triangles[i];
		}
		for (int i = 0; i < numEllipses; i++) {
			delete ellipses[i];
		}
		delete[]circles;
		delete[]lines;
		delete[]triangles;
		delete[]rects;
		delete[]ellipses;
		circles = nullptr;
		rects = nullptr;
		lines = nullptr;
		triangles = nullptr;
		ellipses = nullptr;
	}
};

int main() {
	initScreen();

	int numCircles, numRects, numLines, numTriangles, numEllipses;
	cout << "Enter number of circles: ";
	cin >> numCircles;
	cout << "Enter number of rectangles: ";
	cin >> numRects;
	cout << "Enter number of lines: ";
	cin >> numLines;
	cout << "Enter number of triangles: ";
	cin >> numTriangles;
	cout << "Enter number of ellipses: ";
	cin >> numEllipses;

	Picture pic(numCircles, numRects, numLines, numTriangles, numEllipses);

	for (int i = 0; i < numCircles; i++) {
		int x, y, r;
		cout << "Circle " << i << " (x y r): ";
		cin >> x >> y >> r;
		pic.setCircle(i, new Circle(x, y, r));
	}

	for (int i = 0; i < numRects; i++) {
		int x1, y1, x2, y2;
		cout << "Rect " << i << " (x1 y1 x2 y2): ";
		cin >> x1 >> y1 >> x2 >> y2;
		pic.setRect(i, new Rect(x1, y1, x2, y2));
	}

	for (int i = 0; i < numLines; i++) {
		int x1, y1, x2, y2;
		cout << "Line " << i << " (x1 y1 x2 y2): ";
		cin >> x1 >> y1 >> x2 >> y2;
		pic.setLine(i, new Line(x1, y1, x2, y2));
	}

	for (int i = 0; i < numTriangles; i++) {
		int x1, y1, x2, y2, x3, y3;
		cout << "Triangle " << i << " (x1 y1 x2 y2 x3 y3): ";
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		pic.setTriangle(i, new Triangle(x1, y1, x2, y2, x3, y3));
	}

	for (int i = 0; i < numEllipses; i++) {
		int r, x1, y1, x2, y2;
		cout << "Ellipse " << i << " (r x1 y1 x2 y2): ";
		cin >> r >> x1 >> y1 >> x2 >> y2;
		pic.setEllipse(i, new Ellipse(r, x1, y1, x2, y2));
	}
		
	pic.draw();

	renderScreen();

	return 0;
}
