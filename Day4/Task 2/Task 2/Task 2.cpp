// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int fibonacci(int);

int main()
{
	int x;
	cout << "Enter Index num: " << endl;
	cin >> x;
	int result = fibonacci(x);
	cout << result<<endl;
}
int fibonacci(int index) {
	if (index <= 1)
		return index;
	return fibonacci(index - 1)+ fibonacci(index - 2);
}