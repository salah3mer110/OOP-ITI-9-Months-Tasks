// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Overload {
	int x, y;
public:
	void sum(int x, int y) {
		cout << "With 2 params" << endl;
		cout<< x + y<<endl;
	}
	void sum(int x) {
		cout << "With 1 params" << endl;
		cout<< x + x<<endl;
	}
};

int main()
{
	Overload o1;
	int x = 3, y = 4;
	o1.sum(x);
	o1.sum(x,y);
}
