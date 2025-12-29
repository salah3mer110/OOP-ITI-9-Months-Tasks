// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap(int&, int&);

int main()
{
	int x=2, y=3;
	//cin >> x;
	//cin >> y;
	swap(x, y);
	cout <<"x = " << x << "\ny = "<< y;
}
void swap(int &x, int & y){
	int temp = x;
	x = y;
	y = temp;
}
