// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swapRef(int&, int&);
void swapAdd(int*, int*);
int main()
{
	int x = 2, y = 3;
	int* xptr = &x;
	int* yptr = &y;
	swapRef(x, y);
	cout << "Reference swap=>   " << "x = " << x << "   y = " << y << endl;
	swapRef(*xptr, *yptr);
	cout << "Address swap=>   " << "x = " << x << "   y = " << y<<endl;
}
void swapRef(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void swapAdd(int* xptr, int *yptr) {
	int temp = *xptr;
	*xptr = *yptr;
	*yptr = temp;
}