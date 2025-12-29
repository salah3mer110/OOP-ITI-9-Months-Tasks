// Task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <span>
using namespace std;

void sliceArr(span<int> arr);

int main()
{
	array<int,6> arr= {1, 2, 3, 4, 5, 6};
	sliceArr(arr);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}
void sliceArr(span<int> arr) {
	int halfSize = arr.size() / 2;
	auto firstHalf = arr.subspan(0, halfSize);
	auto secHalf = arr.subspan(halfSize,arr.size() - halfSize);
	for (int i =0 ; i < firstHalf.size(); i++)
		firstHalf[i] = 0;
	for (int i = 0; i < secHalf.size(); i++)
		secHalf[i] = 1;
}

