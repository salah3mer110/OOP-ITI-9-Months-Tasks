// Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;

void convertDeciToBinary(int);

int main()
{
convertDeciToBinary(13);
return 0;
}
void convertDeciToBinary(int num) {
	if (num > 1) 
		convertDeciToBinary(num/2);
	cout<<num % 2;
}
