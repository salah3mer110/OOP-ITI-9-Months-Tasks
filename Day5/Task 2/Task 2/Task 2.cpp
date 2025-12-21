// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;
int main()
{
	int* arr = new int[2];
	for (int i = 0;i < 2;i++) {
		cout << "Enter value " << i + 1 << endl;
		cin >> *(arr + i);
	}
	cout << "Values u entered is =>   ";
	for (int i = 0;i < 2;i++) {
		cout << *(arr + i)<<"  ";
	}

}

